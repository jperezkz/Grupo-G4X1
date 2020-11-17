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
#define tresshold 120
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
	float x, y;
    RoboCompLaser::TLaserData lData;
    float r;
    std::vector<clave>tuplas, nuevo;
    clave sigTarget;

    if(auto t = target.get(); t.has_value()){
        T = t.value();
    }
/*
    if (dist < tresshold) {
        differentialrobot_proxy->setSpeedBase(0, 0);
        target.set_task_finished();
    }
    else {
*/
        lData = laser_proxy->getLaserData();
        for (auto &l: lData)
            p << QPointF(l.dist * cos(l.angle), l.dist * sin(l.angle));

        for (int v = 0; v <= 1000; v = v + 100) {
            for (float a = -1; a <= 1; a = a + 0.2) {
                if (fabs(a) > 0.01) {
                    r = v / a;
                    x = r - r * cos(a);
                    y = r * sin(a);
                    tuplas.push_back(std::make_tuple(x, y, v, a));
                }
            }
        }

        for (auto &[x, y, v, a] : tuplas) {
            if (p.containsPoint(QPointF(x, y), Qt::OddEvenFill)) {
                nuevo.emplace_back(std::make_tuple(x, y, v, a));
            }
        }

        std::sort(nuevo.begin(), nuevo.end(), [T](const auto &a, const auto &b) {
            const auto &[ax, ay, av, aa] = a;
            const auto &[bx, by, bv, ba] = b;
            return (pow(ax - T.x(), 2) + pow(ay - T.y(), 2) < pow(bx - T.x(), 2) + pow(by - T.y(), 2));
        });

        sigTarget = nuevo.front();
        differentialrobot_proxy->setSpeedBase(std::get<2>(sigTarget), std::get<3>(sigTarget));

    /*
    if (dist < tresshold) {
        differentialrobot_proxy->setSpeedBase(0, 0);
        target.set_task_finished();
    }
    else if (fabs(rot) > 0.1) {
        differentialrobot_proxy->setSpeedBase(400, rot);
    }
    else {
        if(dist > 500)
            differentialrobot_proxy->setSpeedBase(900, 0);
        else
            differentialrobot_proxy->setSpeedBase(400, 0);
    }
     */
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

