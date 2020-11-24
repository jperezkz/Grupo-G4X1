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

Eigen::Vector2f SpecificWorker::calcularRotacion(Eigen::Vector2f Tw, Eigen::Vector2f Rw, float alpha, float & rot){
    Eigen::Vector2f Tr(NULL, NULL);
   if(target.isActive()) {

       float angle, alphaGrad;
       Tr = Tw - Rw;

       alphaGrad = qRadiansToDegrees(alpha);
       //alphaGrad = qRadiansToDegrees(alpha);
       while (alphaGrad > 360) alphaGrad -= 360;

       angle = Tr.y() / (sqrt(pow(Tr.x(), 2) + pow(Tr.y(), 2)));
       angle = qRadiansToDegrees(acos(angle));

       if (Tw.x() < Rw.x()) angle = 360 - angle;
       std::cout << "Angulo de objetivo: " << angle << std::endl;
       std::cout << "Angulo de robot: " << alphaGrad << std::endl;

       Eigen::Matrix2f M;
       M << cos(alpha), sin(alpha),
            0 - sin(alpha), cos(alpha);

       Eigen::Vector2f Beta = M.transpose() * Tr;
       if (alphaGrad <= angle && (angle - alphaGrad) < 180) {
           rot = atan2(Beta.x(), Beta.y());
           std::cout << "Angulo a girar der: " << qRadiansToDegrees(rot) << endl;
       } else {
           if ((angle - alphaGrad) > 180) {
               Beta = M * Tr;
               rot = atan2(Beta.x(), Beta.y());
               std::cout << "Angulo a girar izq: " << qRadiansToDegrees(rot) << endl;
           } else {
               rot = atan2(Beta.x(), Beta.y());
               std::cout << "Angulo a girar der: " << qRadiansToDegrees(rot) << endl;
           }
       }
   }
    return Tr;
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

    Eigen::Vector2f Tw(NULL, NULL);
	int RWx, RWy;
	float alpha, dist, rot;

    if(auto t = target.get(); t.has_value()){
        Tw = t.value();
    }

    differentialrobot_proxy->getBasePose(RWx, RWy, alpha);
    Eigen::Vector2f Rw(RWx, RWy);

    Eigen::Vector2f Tr = calcularRotacion(Tw, Rw, alpha, rot);

    dist = sqrt(pow(Tr.x(), 2) + pow(Tr.y(), 2));

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

