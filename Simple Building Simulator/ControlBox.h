#pragma once

#ifndef _control_H
#define _control_H

#include "defs.h"

#include <iostream>
#include<Eigen/Dense>

namespace SimpleBuildingSimulator {
	struct ControlVariables
	{
		float SAT_Value;
		Eigen::MatrixXf SAT;
		Eigen::MatrixXf SAV_Zones;
		Eigen::MatrixXf SAV_Matrix;
		Eigen::MatrixXi SPOT_CurrentState;
	}; 
	class ControlBox
	{
	public:
		ControlBox();
		~ControlBox();
		struct ControlVariables DefaultControl(uint8 num_zones, uint8 num_rooms);
		struct ControlVariables ReactiveControl(uint8 num_zones, uint8 num_rooms, Eigen::MatrixXf TR1,
			Eigen::MatrixXf O, int k, Eigen::MatrixXi SPOT_PreviousState);
	private:
		Eigen::MatrixXf GetSAVMatrix(Eigen::MatrixXf SAV_Zones, int num_rooms, int total_rooms);
	};

}
#endif // !_ControlBox_H