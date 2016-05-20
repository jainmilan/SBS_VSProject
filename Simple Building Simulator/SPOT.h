#pragma once

#ifndef _SPOT_H
#define _SPOT_H

#include "defs.h"
#include<Eigen/Dense>

namespace SimpleBuildingSimulator {
	class SPOT
	{
	public:
		SPOT();
		~SPOT();
		Eigen::MatrixXi GetSPOTForecast(uint16 duration, uint16 time_step, uint8 num_zones, uint8 num_rooms);
	private:

	};
}

#endif // !_SPOT_H
