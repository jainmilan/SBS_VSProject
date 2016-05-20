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
		Eigen::MatrixXi GetOccupancyForecast(uint16 duration, uint16 time_step, uint8 num_zones, uint8 num_rooms);
	private:

	};

}

#endif // !_occupancy_H
