#include "control.h"

using namespace SimpleBuildingSimulator;

ControlBox::ControlBox()
{
}

ControlBox::~ControlBox()
{
}

Eigen::MatrixXf ControlBox::GetSAVMatrix(Eigen::MatrixXf SAV_Zones, int num_rooms, int total_rooms) {
	Eigen::MatrixXf SAV_Zones_Rep = SAV_Zones.replicate(1, num_rooms);

	Eigen::VectorXf SAV_Matrix_Diagonal(Eigen::Map<Eigen::VectorXf>(SAV_Zones_Rep.data(), SAV_Zones_Rep.cols() * SAV_Zones_Rep.rows()));

	Eigen::MatrixXf SAVMatrix = Eigen::MatrixXf::Zero(total_rooms, total_rooms);
	SAVMatrix = SAV_Matrix_Diagonal.asDiagonal();

	return SAVMatrix;
}


struct ControlVariables ControlBox::DefaultControl(uint8 num_zones, uint8 num_rooms) {
	int total_rooms = num_zones * num_rooms;

	struct ControlVariables cv;

	cv.SAT_Value = 30;

	cv.SAT = Eigen::MatrixXf::Ones(1, total_rooms) * cv.SAT_Value;

	cv.SAV_Zones = Eigen::MatrixXf::Ones(num_zones, 1) * 0.05f;
	
	cv.SAV_Matrix = GetSAVMatrix(cv.SAV_Zones, num_rooms, total_rooms);

	cv.SPOT_State = Eigen::MatrixXi::Ones(1, total_rooms);

	return cv;
}