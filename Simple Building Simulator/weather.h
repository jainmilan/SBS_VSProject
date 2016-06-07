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
		Eigen::MatrixXf GetWeatherForecast(long int duration, int time_step, int num_zones, int num_rooms);
	private:

	};
}

#endif // !_weather_H