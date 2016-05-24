#pragma once

#ifndef _control_H
#define _control_H

#include "defs.h"

#include<Eigen/Dense>

namespace SimpleBuildingSimulator {
	struct ControlVariables
	{
		float SAT_Value;
		Eigen::MatrixXf SAT;
		Eigen::MatrixXf SAV_Zones;
		Eigen::MatrixXf SAV_Matrix;
		Eigen::MatrixXi SPOT_State;
	}; 
	class ControlBox
	{
	public:
		ControlBox();
		~ControlBox();
		struct ControlVariables DefaultControl(uint8 num_zones, uint8 num_rooms);
	private:
		Eigen::MatrixXf GetSAVMatrix(Eigen::MatrixXf SAV_Zones, int num_rooms, int total_rooms);
	};

}
#endif // !_ControlBox_H