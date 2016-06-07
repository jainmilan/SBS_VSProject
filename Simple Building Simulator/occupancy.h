#pragma once

#ifndef _occupancy_H
#define _occupancy_H

#include "defs.h"
#include<Eigen/Dense>

namespace SimpleBuildingSimulator {
	class Occupants
	{
	public:
		Occupants();
		~Occupants();
		Eigen::MatrixXi GetOccupancyForecast(long int duration, int time_step, int num_zones, int num_rooms);
	private:

	};

}

#endif // !_occupancy_H
