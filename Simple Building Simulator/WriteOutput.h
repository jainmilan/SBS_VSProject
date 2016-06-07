#pragma once

#ifndef _WriteOutput_H
#define _WriteOutput_H

#include "Building.h"
#include <Eigen\Dense>

namespace SimpleBuildingSimulator {
	class WriteOutput
	{
	public:
		WriteOutput();
		~WriteOutput();
		void WriteOutputCSV(long int duration, int time_step, int num_zones, int num_rooms, Eigen::MatrixXf T, Eigen::MatrixXf TR1, Eigen::MatrixXf TR2,
			Eigen::MatrixXf DeltaTR1, Eigen::MatrixXf DeltaTR2, Eigen::MatrixXf PPV, Eigen::MatrixXf MixedAirTemperature, Eigen::MatrixXf PowerAHU, Eigen::MatrixXf Occupancy,
			Eigen::MatrixXf T_ext, Eigen::MatrixXi SPOT_State, Building::Room CommonRoom, Building::AHU CommonAHU, Building::Air CommonAir, Building::PMV_Model PMV_Params);
	private:

	};

}

#endif // !_occupancy_H