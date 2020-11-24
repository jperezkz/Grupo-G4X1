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
#define tresshold 250
#define ROBOT_LENGTH 400
template<typename TPos>

struct Target{
    TPos content;
    bool active = false;
    std::mutex myMutex;

    void put(const TPos &data){
        std::lock_guard<std::mutex> guard(myMutex);
          content = data;
          active = true;
    }

    bool isActive(){
        return active;
    }

    std::optional<TPos> get(){
        std::lock_guard<std::mutex> guard(myMutex);
        if (active)
            return content;
        else
            return {};
    }

    void set_task_finished()
    {
        std::lock_guard<std::mutex> guard(myMutex);
        active = false;
    }
};
Target<Eigen::Vector2f> target;

class vector2f;

class vector2f;

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
//	try
//	{
//		RoboCompCommonBehavior::Parameter par = params.at("InnerModelPath");
//		std::string innermodel_path = par.value;
//		innerModel = std::make_shared(innermodel_path);
//	}
//	catch(const std::exception &e) { qFatal("Error reading config params"); }






	return true;
}

void SpecificWorker::initialize(int period)
{
	std::cout << "Initialize worker" << std::endl;
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
	//computeCODE
	/*
	QMutexLocker locker(mutex);
	try
	{
	  camera_proxy->getYImage(0,img, cState, bState);
	  memcpy(image_gray.data, &img[0], m_width*m_height*sizeof(uchar));
	  searchTags(image_gray);
	}
	catch(const Ice::Exception &e)
	{
	  std::cout << "Error reading from Camera" << e << std::endl;
	}
    */

	QPolygonF p;
    Eigen::Vector2f T(NULL, NULL);
	float dist;
	RoboCompGenericBase::TBaseState tBase;
    std::vector<clave>tuplas, nuevo;
    clave sigTarget;

    if(auto t = target.get(); t.has_value()){
        T = t.value();
    }
    differentialrobot_proxy->getBaseState(tBase);
    dist = sqrt(pow(T.x()- tBase.x,  2) + pow(T.y() - tBase.z , 2));

    std::cout << "Velocidad actual: " << tBase.advVz << " Rot actual: " << tBase.rotV << endl;
    std::cout << "Xpos: " << tBase.x << " Ypos: " << tBase.z << endl;
    std::cout << "Dist: " << dist << endl;

    if (dist < tresshold) {
        differentialrobot_proxy->setSpeedBase(0, 0);
        target.set_task_finished();
    }
    else {
        if(target.isActive()) {
            generarPoligono(p);
            calculoPuntos(tBase.advVz, tBase.rotV, tuplas);
            ordenarPuntos(p, tuplas, nuevo, T);
/*
        // graphics
        QGraphicsView *graphicsView;
        QGraphicsItem *robot_polygon;
        QGraphicsScene scene;
        scene.addText("Window");

        graphicsView = new QGraphicsView(this);
        graphicsView->resize(this->size());
        graphicsView->setScene(&scene);
        graphicsView->setMinimumSize(400,400);
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
        robot_polygon = (QGraphicsItem*) scene.addPolygon(poly2, QPen(QColor("DarkRed")), brush);
        robot_polygon->setZValue(5);
        RoboCompGenericBase::TBaseState bState;
        try
        {
            differentialrobot_proxy->getBaseState(bState);
            robot_polygon->setRotation(qRadiansToDegrees(-bState.alpha));
            robot_polygon->setPos(bState.x,bState.z);
        }
        catch (const Ice::Exception &e) { std::cout << e.what() << std::endl; }

// box
        auto caja = innerModel->getTransform("caja1");
        scene.addRect(caja->backtX-200, caja->backtZ-200, 400, 400, QPen(QColor("Magenta")), QBrush(QColor("Magenta")));
        graphicsView->fitInView(scene.sceneRect(), Qt::KeepAspectRatio );

*/
            if (nuevo.empty()) {
                std::cout << "Nuevo esta vacio" << endl;
            }
            if (tuplas.empty())
                std::cout << "tuplas esta vacio" << endl;

            sigTarget = tuplas.front();
            std::cout << "VAplicada: " << get<2>(sigTarget) << " RotAplicada: " << get<3>(sigTarget) << endl;
            differentialrobot_proxy->setSpeedBase(std::get<2>(sigTarget), std::get<3>(sigTarget));

            //delete graphicsView;
        }
    }
}

void SpecificWorker::generarPoligono(QPolygonF &p){
    RoboCompLaser::TLaserData lData = laser_proxy->getLaserData();

    for (auto &l: lData)
        p << QPointF(l.dist * cos(l.angle), l.dist * sin(l.angle));
}

void SpecificWorker::calculoPuntos(float vOrigen, float aOrigen,std::vector<clave> &tuplas) {
    float vActual, aActual;
    float r, x, y, alpha;

    for(float dt = 0.3; dt<1.5; dt += 0.1) {
        for (int v = 0; v <= 1000; v = v + 100) {
            for (float a = -3; a <= 3; a += 0.1) {
                vActual = vOrigen + v;
                aActual = aOrigen + a;
                if (fabs(aActual) > 0.01) {
                        r = vActual / aActual;
                        x = r - r * cos(aActual * dt);
                        y = r * sin(aActual * dt);
                        alpha = aActual * dt;
                        tuplas.push_back(std::make_tuple(x, y, vActual, aActual, alpha));
                }
                else{
                    tuplas.push_back(std::make_tuple(0, v * dt, vActual, aActual, aActual * dt));
                }
            }
        }
    }
}

void SpecificWorker::ordenarPuntos(QPolygonF p, std::vector<clave> &tuplas, std::vector<clave> &nuevo, Eigen::Vector2f T){

    for (auto &[x, y, v, a, al] : tuplas) {
        if (p.containsPoint(QPointF(x, y), Qt::OddEvenFill)) {
            nuevo.emplace_back(std::make_tuple(x, y, v, a, al));
            //std::cout << "Se llena nuevo" << endl;
        }
    }
    //std::cout <<"Primer punto nuevo --> X: " << get<2>(nuevo.front()) << " Y: " << get<2>(nuevo.front()) << endl;
    std::sort(tuplas.begin(), tuplas.end(), [T](const auto &a, const auto &b) {
        const auto &[ax, ay, av, aa, ap] = a;
        const auto &[bx, by, bv, ba, bp] = b;
        return (pow(ax - T.x(), 2) + pow(ay - T.y(), 2) < pow(bx - T.x(), 2) + pow(by - T.y(), 2));
    });
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

