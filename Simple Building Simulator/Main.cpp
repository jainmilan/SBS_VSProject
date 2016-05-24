#include<stdio.h>
#include<iostream>
#include<string>

#include "defs.h"
#include "print.h"

#include "building.h"

using namespace SimpleBuildingSimulator;
using namespace Eigen;

int main()
{
	/* Initialize Building */
	Building dc;
	
	uint8 num_zones = dc.get_num_zones();
	uint8 num_rooms = dc.get_num_rooms();

	int update = 0;

	printf("DEFAULT: \n Number of Zones = %hhu \n Number of Rooms = %hhu \n", num_zones, num_rooms);
	
	printf("Do you want to change? (1-Yes, 0-No): ");
	scanf_s("%d", &update);

	if (update == 1) {
		printf("WARNING: Number should lie between 0-255. Otherwise, Unexpected Results\n");

		printf("Enter Number of Zones : ");
		scanf_s("%hhu", &num_zones);
		dc.set_num_zones(num_zones);

		printf("Enter Number of Rooms : ");
		scanf_s("%hhu", &num_rooms);
		dc.set_num_rooms(num_rooms);
	}
	
	num_zones = dc.get_num_zones();
	num_rooms = dc.get_num_rooms();

	printf("UPDATED: \n Number of Zones = %hhu \n Number of Rooms = %hhu \n", num_zones, num_rooms);
	
	/* Initialize Simulation Details */
	uint16 duration = 2000;
	uint16 time_step = 600;

	printf("DEFAULT: \n Duration = %hu \n Time Step = %hu \n", duration, time_step);

	printf("Do you want to change? (1-Yes, 0-No): ");
	scanf_s("%d", &update);

	if (update == 1) {
		printf("Enter Simulation Duration (in seconds) : ");
		scanf_s("%hu", &duration);

		printf("Enter Time Step (in seconds) : ");
		scanf_s("%hu", &time_step);
	}

	if ((time_step/60) > duration) {
		printf("ERROR: Time step can't be greater than total duration of simulation");
		return 0;
	}

	printf("Updated: \n Duration = %hu \n Time Step = %hu \n", duration, time_step);

	/*
	Eigen::MatrixXf m1 = dc.Create_CoWI_CRT_Matrix(time_step);
	std::cout << m1 << std::endl;
	printf("\n");

	Eigen::MatrixXf m2 = dc.Create_CoWI_OAT_Matrix(time_step);
	std::cout << m2 << std::endl;
	printf("\n");

	Eigen::MatrixXf m3 = dc.Create_CoHI_CRT_Matrix(time_step);
	std::cout << m3 << std::endl;
	printf("\n");

	Eigen::MatrixXf m4 = dc.Create_CoHI_SAT_Matrix(time_step);
	std::cout << m4 << std::endl;
	printf("\n");

	Eigen::MatrixXf m5 = dc.Create_CoEI_OLEL_Matrix(time_step);
	std::cout << m5 << std::endl;
	printf("\n");

	Eigen::MatrixXf m6 = dc.Create_CoOI_OHL_Matrix(time_step);
	std::cout << m6 << std::endl;
	printf("\n");

	Eigen::MatrixXf m7 = dc.Create_CoSI_SCS_Matrix(time_step);
	std::cout << m7 << std::endl;
	printf("\n");

	Eigen::MatrixXf m8 = dc.Create_CoRC_CiRT_Matrix(time_step);
	std::cout << m8 << std::endl;
	printf("\n");

	Eigen::MatrixXf m9 = dc.Create_CoRC_CiR1T_Matrix(time_step);
	std::cout << m9 << std::endl;
	printf("\n");

	Weather forecast;
	Eigen::MatrixXf m10 = forecast.GetWeatherForecast(duration, time_step, num_zones, num_rooms);
	std::cout << m10 << std::endl;
	printf("\n");

	Occupants occupancy;
	Eigen::MatrixXi m11 = occupancy.GetOccupancyForecast(duration, time_step, num_zones, num_rooms);
	std::cout << m11 << std::endl;
	printf("\n");

	SPOT spot;
	Eigen::MatrixXi m12 = spot.GetSPOTForecast(duration, time_step, num_zones, num_rooms);
	std::cout << m12 << std::endl;
	printf("\n");
	*/
	dc.Simulate(duration, time_step);

	system("pause");
	return 0;
}