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

/**
	\brief
	@author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <innermodel/innermodel.h>
#include <Eigen/Dense>
#include <QGraphicsView>
#include <QGraphicsItem>



class SpecificWorker : public GenericWorker
{
	using tupla = std::tuple<float, float, float, float, float>;
Q_OBJECT
public:
	SpecificWorker(TuplePrx tprx, bool startup_check);
	~SpecificWorker();
	bool setParams(RoboCompCommonBehavior::ParameterList params);
	void RCISMousePicker_setPick(RoboCompRCISMousePicker::Pick myPick);

public slots:
	void compute();
    void generarPoligono(QPolygonF &p);
    void calculoPuntos(float vOrigen, float rOrigen, std::vector<tupla>&tuplas);
    void ordenarPuntos(QPolygonF p, std::vector<tupla> &tuplas, std::vector<tupla> &nuevo, Eigen::Vector2f T);
	int startup_check();
	void initialize(int period);

private:
 	
	std::shared_ptr < InnerModel > innerModel;
	bool startup_check_flag;

	 //draw
    QGraphicsScene scene;
    QGraphicsView *graphicsView;
    QGraphicsItem *robot_polygon = nullptr;
    QGraphicsItem *laser_polygon = nullptr;
    const float ROBOT_LENGTH = 400;

    void draw_things(const RoboCompGenericBase::TBaseState &bState, const RoboCompLaser::TLaserData &ldata, const std::vector<tupla> &puntos, const tupla &front);
    std::vector<QGraphicsEllipseItem*> arcs_vector;

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


};

#endif
