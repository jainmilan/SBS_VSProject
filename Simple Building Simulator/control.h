#pragma once

#ifndef _control_H
#define _control_H

#include "defs.h"

#include<Eigen/Dense>

namespace SimpleBuildingSimulator {
	struct ControlVariables
	{
		Eigen::MatrixXf SAT;
		Eigen::MatrixXf SAV;
		Eigen::MatrixXi SPOT_State;
	}; 
	class ControlBox
	{
	public:
		ControlBox();
		~ControlBox();
		struct ControlVariables DefaultControl(uint8 num_zones, uint8 num_rooms);

	private:
		
	};

}
#endif // !_ControlBox_H