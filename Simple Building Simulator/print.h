#pragma once

#ifndef _print_H
	#define _print_H

#include<stdio.h>

#include "defs.h"
namespace SimpleBuildingSimulator {
	void printMatrix(float ** matrix, uint8 num_zones, uint8 num_rooms);
	void printMatrix(uint8 ** matrix, uint8 num_zones, uint8 num_rooms);
}
#endif // !_print_H
