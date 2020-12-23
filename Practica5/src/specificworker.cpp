/*
 *    Copyright (C) 2020 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"

/**
* \brief Default constructor
*/

SpecificWorker::SpecificWorker(TuplePrx tprx, bool startup_check) : GenericWorker(tprx)
{
	this->startup_check_flag = startup_check;
}

/**
* \brief Default destructor
*/
SpecificWorker::~SpecificWorker()
{
	std::cout << "Destroying SpecificWorker" << std::endl;
}

bool SpecificWorker::setParams(RoboCompCommonBehavior::ParameterList params)
{
//	THE FOLLOWING IS JUST AN EXAMPLE
//	To use innerModelPath parameter you should uncomment specificmonitor.cpp readConfig method content
	try
	{
		RoboCompCommonBehavior::Parameter par = params.at("InnerModelPath");
		std::string innermodel_path = par.value;
		innerModel = std::make_shared<InnerModel>(innermodel_path);
	}
	catch(const std::exception &e) { qFatal("Error reading config params"); }
	return true;
}

void SpecificWorker::initialize(int period)
{
	std::cout << "Initialize worker" << std::endl;

    // graphics
    graphicsView = new QGraphicsView(this);
    graphicsView->resize(this->size());
    graphicsView->setScene(&scene);
    graphicsView->setMinimumSize(400, 400);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    struct Dimensions
    {
        int TILE_SIZE = 100;
        float HMIN = -2500, VMIN = -2500, WIDTH = 5000, HEIGHT = 5000;
    };
    Dimensions dim;
    scene.setSceneRect(dim.HMIN, dim.VMIN, dim.WIDTH, dim.HEIGHT);
    graphicsView->scale(1, -1);

    graphicsView->show();

    //robot
    QPolygonF poly2;
    float size = ROBOT_LENGTH / 2.f;
    poly2 << QPoint(-size, -size)
          << QPoint(-size, size)
          << QPoint(-size / 3, size * 1.6)
          << QPoint(size / 3, size * 1.6)
          << QPoint(size, size)
          << QPoint(size, -size);
    QBrush brush;
    brush.setColor(QColor("DarkRed"));
    brush.setStyle(Qt::SolidPattern);
    robot_polygon = (QGraphicsItem *)scene.addPolygon(poly2, QPen(QColor("DarkRed")), brush);
    robot_polygon->setZValue(5);

    try
    {
        RoboCompGenericBase::TBaseState bState;
        differentialrobot_proxy->getBaseState(bState);
        robot_polygon->setRotation(qRadiansToDegrees(-bState.alpha));
        robot_polygon->setPos(bState.x, bState.z);
    }
    catch (const Ice::Exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    graphicsView->fitInView(scene.sceneRect(), Qt::KeepAspectRatio);

    fill_grid_with_obstacles(grid);
    grid.create_graphic_items(scene, graphicsView);

    this->Period = period;
	if(this->startup_check_flag)
	{
		this->startup_check();
	}
	else
	{
		timer.start(Period);
	}

}

void SpecificWorker::compute()
{
    RoboCompGenericBase::TBaseState tBase;
    differentialrobot_proxy->getBaseState(tBase);   
    RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData();

	QPolygonF p;
    Eigen::Vector2f T(NULL, NULL);

    std::vector<tupla> tuplas, nuevo, resultados;
    tupla sigTarget;

    if(auto t = target.get(); t.has_value())
    {
        T = t.value();

        // pasarlo al SR del robot
        Eigen::Vector2f rw(tBase.x, tBase.z);
        Eigen::Matrix2f rot;
        rot << cos(tBase.alpha), sin(tBase.alpha), -sin(tBase.alpha), cos(tBase.alpha);
        auto tr = rot.transpose() * (T - rw); // TARGET EN EL ROBOT
        auto dist = tr.norm(); 

        // Llamar a la función waveFront Propagation con el nuevo target
        grid.compute_navigation_function(T);

        if (dist < tresshold)
        {
            differentialrobot_proxy->setSpeedBase(0, 0);
            target.set_task_finished();
            grid.reset_cell_distances();
            return;
        }
        else 
        {
            if(target.isActive()) 
            {
                generarPoligono(p, ldata);
                calculoPuntos(tBase, tuplas);
                nuevo = obstaculos(tuplas, tBase.alpha, ldata);
                ordenarPuntos(nuevo, tr, resultados);

                if(!resultados.empty())    sigTarget = resultados.front();

                auto &[x,y,v,w,a,f] = sigTarget;
                if (w > M_PI) w = M_PI;
                if (w < -M_PI) w = -M_PI;
                if (v < 0) v = 0;

                std::cout << "Estoy en: " << tBase.x <<","<<tBase.z<<" y el objetivo en: "<<x<<","<<y<<endl;
                std::cout << "VAplicada: " << std::min(v/3, 1000.f) << " RotAplicada: " << w << endl;

                differentialrobot_proxy->setSpeedBase(std::min(v/3, 1000.f) , w);
                draw_things(tBase, ldata, resultados, sigTarget);
            }
        }
    }
}   


void SpecificWorker::draw_things(const RoboCompGenericBase::TBaseState &bState, const RoboCompLaser::TLaserData &ldata,
                                 const std::vector<tupla> &puntos, const tupla &front)
{
    //draw robot
    //innerModel->updateTransformValues("base", bState.x, 0, bState.z, 0, bState.alpha, 0);
    robot_polygon->setRotation(qRadiansToDegrees(-bState.alpha));
    robot_polygon->setPos(bState.x, bState.z);
    graphicsView->resize(this->size());

    //draw laser
    if (laser_polygon != nullptr)
        scene.removeItem(laser_polygon);
    QPolygonF poly;
    for (auto &l : ldata)
        poly << robot_polygon->mapToScene(QPointF(l.dist * sin(l.angle), l.dist * cos(l.angle)));
    QColor color("Green");
    color.setAlpha(40);
    laser_polygon = scene.addPolygon(poly, QPen(color), QBrush(color));
    laser_polygon->setZValue(13);

    // draw future. Draw and arch going out from the robot
    // remove existing arcs
    for (auto arc : arcs_vector)
        scene.removeItem(arc);
    arcs_vector.clear();
    QColor col("Red");
    for (auto &[x, y, vx, wx, a, f] : puntos)
    {
        QPointF centro = robot_polygon->mapToScene(x, y);
        arcs_vector.push_back(scene.addEllipse(centro.x(), centro.y(), 20, 20, QPen(col), QBrush(col)));
    }

    QPointF center = robot_polygon->mapToScene(std::get<0>(front), std::get<1>(front));
    arcs_vector.push_back(scene.addEllipse(center.x(), center.y(), 40, 40, QPen(Qt::black), QBrush(Qt::black)));
}



void SpecificWorker::generarPoligono(QPolygonF &p, const RoboCompLaser::TLaserData ldata){
    for (auto &l: ldata)
        p << QPointF(l.dist * cos(l.angle), l.dist * sin(l.angle));
}

void SpecificWorker::calculoPuntos(RoboCompGenericBase::TBaseState tBase,std::vector<tupla> &tuplas) {
    float vActual, aActual;
    float r, x, y, alpha;

    for(float dt = 0.3; dt<1.5; dt += 0.1) {
        for (int v = 0; v <= 1000; v = v + 100) {
            for (float a = -3; a <= 3; a += 0.1) {
                vActual = tBase.advVz + v;
                aActual = tBase.rotV + a;
                if (fabs(aActual) > 0.01) {
                        r = vActual / aActual;
                        x = r - r * cos(aActual * dt);
                        y = r * sin(aActual * dt);
                        alpha = aActual * dt;
                        tuplas.push_back(std::make_tuple(x, y, vActual, aActual, alpha, 0));
                }
                else{
                    tuplas.push_back(std::make_tuple(0, v * dt, vActual, aActual, aActual * dt, 0));
                }
            }
        }
    }
}

void SpecificWorker::ordenarPuntos(std::vector<tupla> vector, Eigen::Vector2f T, std::vector<tupla> &vectorResultados){
    float F, A, B, C;
    float xPeso = 0.1, yPeso = 0.9, zPeso = 0.3;

    for (auto &[x, y, a, g, ang, f] : vector) {
        A = pow(x - T.x(), 2) + pow(y - T.y(), 2);
        if (grid.get_occupied(x, y))
            B = 1000;
        else
            B = grid.get_value(x, y);
        C = ang;
        F = A*xPeso + B*yPeso + C*zPeso;
        vectorResultados.push_back(std::make_tuple(x, y, a, g, ang, F));
    }

    std::sort(vectorResultados.begin(), vectorResultados.end(), [](const auto &a, const auto &b) {
        const auto &[ax, ay, av, aa, ap, af] = a;
        const auto &[bx, by, bv, ba, bp, bf] = b;
        return (af < bf);
    });
}


std::vector<SpecificWorker::tupla> SpecificWorker::obstaculos(std::vector<tupla> vector, float aph, const RoboCompLaser::TLaserData &ldata)
{
    QPolygonF polygonF;
    const float semiancho = 250; // el semiancho del robot
    std::vector<tupla> vectorOBs;
    for (auto &l : ldata)
        polygonF << QPointF(l.dist * sin(l.angle), l.dist * cos(l.angle));

    for (auto &[x, y, a, g, ang, f] : vector) {

        // GENERAR UN CUADRADO CON EL CENTRO EN X, Y Y ORIENTACION ANG.
        QPolygonF polyRobot;

        polyRobot << QPointF(x - semiancho, y + semiancho)
                  << QPointF(x + semiancho, y + semiancho)
                  << QPointF(x + semiancho, y - semiancho)
                  << QPointF(x - semiancho, y - semiancho);

        polyRobot = QTransform().rotate(aph).map(polyRobot);
        //   qDebug () <<  "Despues de girar " <<  polyRobot;

        bool cuatroEsquinas = true;
        for (auto &p : polyRobot) {
            // si NO contiene alguna de las 4 esquinas, no tenemos en cuenta esa x, y .
            //En el momento en el que un punto no coincide, pasamos a otro.
            if (!polygonF.containsPoint(p, Qt::OddEvenFill)) {
                cuatroEsquinas = false;
                break;
            }
        }
        // SI contiene las 4 esquinas , metemos el valor.
        if (cuatroEsquinas) {
            // qDebug() << "CuatroEsquinas es true";
            //    std::cout << FUNCTION << " " << x << " " << y << " " << a << " " << g << " " << ang << std::endl;
            vectorOBs.emplace_back(std::make_tuple(x, y, a, g, ang, f));
        }
    }

    if (vectorOBs.empty()) {
        differentialrobot_proxy->setSpeedBase(5, M_PI/2);
        usleep(1000000);
    }
    return vectorOBs;
}


void SpecificWorker::fill_grid_with_obstacles (Grid &grid)
{

        for(int i=1; i<max_boxes; i++)
        {
            auto caja = "caja" + QString::number(i);
            auto node = innerModel->getNode(caja);
            auto mesh = innerModel->getNode("cajaMesh" + QString::number(i));
            if(node and mesh)
            {
                auto pose = innerModel->transform("world", caja);
                auto plane = dynamic_cast<InnerModelPlane*>(mesh);
                int x = pose.x();
                int z = pose.z();
                int width = plane->depth;
                int depth = plane->width;

                grid.set_occupied(x,z);
                for(int i = x-width/2; i <= (x+width/2); i++)
                {
                    for(int j = z-depth/2; j <= (z+depth/2); j++)
                    {
                        grid.set_occupied(i, j);
                    }
                }

                QPolygonF poly;
                poly << QPoint(x-width/2, z-depth/2)
                     << QPoint(x+width/2, z-depth/2)
                     << QPoint(x+width/2, z+depth/2)
                     << QPoint(x-width/2, z+depth/2);
                QColor color("Blue");
                color.setAlpha(40);
                obstacles_polygon = (QGraphicsItem *)scene.addPolygon(poly, QPen(color), QBrush(color));
                obstacles_polygon->setZValue(13);

            }
        }

        // Marcamos las paredes como obstáculos
        for(int i=-1; i<=1; i+=2) {
            QPolygonF paredVertical, paredHorizontal;
            paredVertical << QPoint(2500*i, -2500)
                      << QPoint(2480*i, -2500)
                      << QPoint(2480*i, 2500)
                      << QPoint(2500*i, 2500);
            paredHorizontal << QPoint(-2500, 2500*i)
                      << QPoint(-2500, 2480*i)
                      << QPoint(2500, 2480*i)
                      << QPoint(2500, 2500*i);
            QColor color("Blue");
            color.setAlpha(40);
            obstacles_polygon = (QGraphicsItem *)scene.addPolygon(paredVertical, QPen(color), QBrush(color));
            obstacles_polygon = (QGraphicsItem *)scene.addPolygon(paredHorizontal, QPen(color), QBrush(color));
            obstacles_polygon->setZValue(13);
        }
}


int SpecificWorker::startup_check()
{
	std::cout << "Startup check" << std::endl;
	QTimer::singleShot(200, qApp, SLOT(quit()));
	return 0;
}


//SUBSCRIPTION to setPick method from RCISMousePicker interface
void SpecificWorker::RCISMousePicker_setPick(RoboCompRCISMousePicker::Pick myPick)
{
//subscribesToCODE
    std::cout << "Coordenada X: " << myPick.x << endl;
    std::cout << "Coordenada Z: " << myPick.z << endl;

    target.put(Eigen::Vector2f(myPick.x, myPick.z));
}



/**************************************/
// From the RoboCompDifferentialRobot you can call this methods:
// this->differentialrobot_proxy->correctOdometer(...)
// this->differentialrobot_proxy->getBasePose(...)
// this->differentialrobot_proxy->getBaseState(...)
// this->differentialrobot_proxy->resetOdometer(...)
// this->differentialrobot_proxy->setOdometer(...)
// this->differentialrobot_proxy->setOdometerPose(...)
// this->differentialrobot_proxy->setSpeedBase(...)
// this->differentialrobot_proxy->stopBase(...)

/**************************************/
// From the RoboCompDifferentialRobot you can use this types:
// RoboCompDifferentialRobot::TMechParams

/**************************************/
// From the RoboCompLaser you can call this methods:
// this->laser_proxy->getLaserAndBStateData(...)
// this->laser_proxy->getLaserConfData(...)
// this->laser_proxy->getLaserData(...)

/**************************************/
// From the RoboCompLaser you can use this types:
// RoboCompLaser::LaserConfData
// RoboCompLaser::TData

/**************************************/
// From the RoboCompRCISMousePicker you can use this types:
// RoboCompRCISMousePicker::Pick

