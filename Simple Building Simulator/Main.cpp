#define STRICT
#include<windows.h>

#include<string>
#include<stdio.h>
#include<iostream>

#include "defs.h"
#include "print.h"
#include "building.h"

using namespace SimpleBuildingSimulator;
using namespace Eigen;

int main()
{
	/* Initialize Building */
	Building dc;
	
	int num_zones = dc.get_num_zones();
	int num_rooms = dc.get_num_rooms();

	int update = 0;

	printf("DEFAULT: \n Number of Zones = %d \n Number of Rooms = %d \n", num_zones, num_rooms);
	
	printf("Do you want to change? (1-Yes, 0-No): ");
	scanf_s("%d", &update);

	if (update == 1) {
		printf("WARNING: Number should lie between 0-255. Otherwise, Unexpected Results\n");

		printf("Enter Number of Zones : ");
		scanf_s("%d", &num_zones);
		dc.set_num_zones(num_zones);

		printf("Enter Number of Rooms : ");
		scanf_s("%d", &num_rooms);
		dc.set_num_rooms(num_rooms);
	}
	
	num_zones = dc.get_num_zones();
	num_rooms = dc.get_num_rooms();

	printf("UPDATED: \n Number of Zones = %d \n Number of Rooms = %d \n", num_zones, num_rooms);
	
	/* Initialize Simulation Details */
	int MIN2SEC = 60;
	long int duration = 120000;
	int time_step = 600;

	printf("DEFAULT: \n Duration = %ld \n Time Step = %d \n", duration, time_step);

	printf("Do you want to change? (1-Yes, 0-No): ");
	scanf_s("%d", &update);

	if (update == 1) {
		printf("Enter Simulation Duration (in seconds) : ");
		scanf_s("%ld", &duration);

		printf("Enter Time Step (in seconds) : ");
		scanf_s("%d", &time_step);
	}

	if ((time_step/MIN2SEC)/duration > 1) {
		printf("ERROR: Time step can't be greater than total duration of simulation");
		return 0;
	}

	printf("UPDATED: \n Duration = %ld \n Time Step = %d \n", duration, time_step);

	int control_type = 1;

	printf("DEFAULT: SPOT Always On \n");

	printf("Do you want to change? (1-Yes, 0-No): ");
	scanf_s("%d", &update);

	if (update == 1) {
		printf("Enter Control Type (1 - AlwaysOn, 2 - Reactive, 3 - MPC) : ");
		scanf_s("%d", &control_type);
	}

	if (control_type == 1) {
		printf("Updated: SPOT Always On \n");
	}
	else if (control_type == 1) {
		printf("Updated: Reactive Control \n");
	}
	else {
		printf("Updated: MPC Control \n");
	}
		
	dc.Simulate(duration, time_step, control_type);
	printf("Simulation Complete");
	system("pause");
	return 0;
}