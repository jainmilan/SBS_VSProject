#include "print.h"

using namespace SimpleBuildingSimulator;

void SimpleBuildingSimulator::printMatrix(float ** matrix, uint8 num_zones, uint8 num_rooms) {
	for (uint8 i = 0; i < num_zones*num_rooms; i++) {
		for (uint8 j = 0; j < num_zones*num_rooms; j++) {
			printf("%f ", matrix[i][j]);
		}
		printf("\n");
	}
}

void SimpleBuildingSimulator::printMatrix(uint8 ** matrix, uint8 num_zones, uint8 num_rooms) {
	for (uint8 i = 0; i < num_zones*num_rooms; i++) {
		for (uint8 j = 0; j < num_zones*num_rooms; j++) {
			printf("%hhu ", matrix[i][j]);
		}
		printf("\n");
	}
}
