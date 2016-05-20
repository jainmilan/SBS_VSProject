#include "control.h"

using namespace SimpleBuildingSimulator;

ControlBox::ControlBox()
{
}

ControlBox::~ControlBox()
{
}

struct ControlVariables ControlBox::DefaultControl(uint8 num_zones, uint8 num_rooms) {
	int total_rooms = num_zones * num_rooms;

	struct ControlVariables cv;

	float SAT_Value = 30;
	cv.SAT = Eigen::MatrixXf::Ones(1, total_rooms) * SAT_Value;

	cv.SAV = Eigen::MatrixXf::Identity(total_rooms, total_rooms);

	cv.SPOT_State = Eigen::MatrixXi::Ones(1, total_rooms);

	return cv;
}