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

#define TAM 50
#define SECTIONS 2
#define CSeccion 2500
int section;

/**
* \brief Default constructor
*/
SpecificWorker::SpecificWorker(MapPrx& mprx, bool startup_check) : GenericWorker(mprx)
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

void SpecificWorker::initializeMap()
{
    clave p;

    for(int i=-TAM; i<=TAM; i++) {
        for (int j = -TAM; j <= TAM; j++){
            p.first = i + 50;
            p.second = j + 50;
            mapR[p] = false;
        }
    }
}

void SpecificWorker::initialize(int period)
{
	std::cout << "Initialize worker" << std::endl;
	this->Period = period;

	// Inicializar el mapa
	initializeMap();

	if(this->startup_check_flag)
	{
		this->startup_check();
	}
	else
	{
		timer.start(Period);
	}
}

clave SpecificWorker::key(int x, int y)
{
    return std::make_pair((int)(x/TAM + 50), (int)(y/TAM + 50));
}
/*
int SpecificWorker::calculoCoste(clave p)
 {
    clave pObj;
    int x, y;
    int mCoste = 100, coste;

    for(int i=0; i<=50; i++) {
        for (int j = 0; j <= 50; j++){
            pObj.first = i;
            pObj.second = j;
            if(!mapR[pObj]){
                x = pObj.first - p.first;
                y = pObj.second - p.second;
                coste = fabs(x) + fabs(y);
                if (coste < mCoste)
                    mCoste = coste;
            }
        }
    }
    return mCoste;
}
*/

void SpecificWorker::marcarCeldas(clave p)
{
    mapR[p] = true; //x y
    p.second++;
    mapR[p] = true; //x y+1
    p.first++;
    p.second--;
    mapR[p] = true; //x+1 y
    p.first--;
    p.second--;
    mapR[p] = true; //x y-1
    p.first--;
    p.second++;
    mapR[p] = true; //x-1 y
}

int SpecificWorker::getLocation(clave p)
{
    int s = 1;

    if(p.first > 50) s = 4;
    if(p.second > 50) s = 2;
    if(p.first > 50 && p.second > 50) s = 3;

    return s;
}

float SpecificWorker::calculoRot(RoboCompLaser::TLaserData rdata)
{
    float mediaIzq, mediaDer;
    float rot;

    for (int i = 0; i < 50; i++) {
        mediaDer += rdata[i].dist;
        mediaIzq += rdata[i + 50].dist;
    }
    mediaDer /= 50;
    mediaIzq /= 50;

    if (mediaIzq >= mediaDer)
        rot = -1.6;
    else
        rot = 1.6;

        return rot;
}

bool SpecificWorker::calcularSeccion(int x, int y)
{
    int secX = 0, secY = 0, topeX = 50, topeY = 50;
    int contVis=0;
    clave sec = key(x,y);
    clave pair;
    float porcentaje;

    switch (getLocation(sec)) {
        case 2:
            secY += 50;
            topeY += 50;
            break;
        case 3:
            secX += 50;
            topeX += 50;
            secY += 50;
            topeY += 50;
            break;
        case 4:
            secX += 50;
            topeX += 50;
            break;
    }

    while(secX<=topeX){
        while(secY<=topeY){
            pair = std::make_pair(secX, secY);
            if (mapR[pair])
                contVis ++;
            secY++;
        }
        secY -= 50;
        secX++;
    }
    porcentaje = (contVis * 100) / CSeccion;
    std::cout << "Estamos en la seccion [" << sec.first <<"] ["<< sec.second <<"] con un " << porcentaje << "%" << endl;

    return  porcentaje > 20;
}

void SpecificWorker::compute()
{
    const float threshold = 200; // millimeters
    float rot;  // rads per second
    float alpha;
    int x, y;
    clave p, sec;

    try {
        // read laser data
        RoboCompLaser::TLaserData ldata = laser_proxy->getLaserData();
        //sort laser data from small to large distances using a lambda function.
        std::sort(ldata.begin(), ldata.end(),
                  [](RoboCompLaser::TData a, RoboCompLaser::TData b) { return a.dist < b.dist; });
        differentialrobot_proxy->getBasePose(x, y, alpha);
        p = key(x, y);

        marcarCeldas(p);
        //std::cout << "La celda [" << p.first << "][" << p.second <<"] ha sido visitada" << std::endl;
        //std::cout << "Angulo: " << alpha << endl;
        
	if( ldata.front().dist < threshold)
	{
		std::cout << ldata.front().dist << std::endl;
		//calculoCoste(p);
		if(calcularSeccion(x, y)) {
            std::cout <<"Ya estaria"<<endl;
            std::cout <<"Seccion: " << section << endl;
            section = 0;
		}
		else{
		    std::cout << "Seguir visitando"<<endl;
		    section = getLocation(p);
            std::cout <<"Seccion: " << section << endl;
		}
        RoboCompLaser::TLaserData rdata = laser_proxy->getLaserData();
        rot = calculoRot(rdata);
 		differentialrobot_proxy->setSpeedBase(5, rot);
		usleep(rand()%(1500000-100000 + 1) + 100000);  // random wait between 1.5s and 0.1sec
	}
	else
	{
	    if(getLocation(p) != section && section != 0){
            differentialrobot_proxy->setSpeedBase(5, 2);
            std::cout << "Esta girando para volver a la seccion "<< section << endl;
	    }
	    differentialrobot_proxy->setSpeedBase(800, 0);
  	}
    }
    catch(const Ice::Exception &ex)
    {
        std::cout << ex << std::endl;
    }
	
	
}

int SpecificWorker::startup_check()
{
	std::cout << "Startup check" << std::endl;
	QTimer::singleShot(200, qApp, SLOT(quit()));
	return 0;
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

