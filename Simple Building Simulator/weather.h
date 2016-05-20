#pragma once

#ifndef _weather_H

#define _weather_H

#include "defs.h"	
#include<Eigen/Dense>

namespace SimpleBuildingSimulator {
	class Weather
	{
	public:
		Weather();
		~Weather();
		Eigen::MatrixXf GetWeatherForecast(uint16 duration, uint16 time_step, uint8 num_zones, uint8 num_rooms);
	private:

	};
}

#endif // !_weather_H