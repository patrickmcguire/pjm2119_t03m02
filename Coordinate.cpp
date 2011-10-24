/*
 * Coordinate.cpp
 *
 *  Created on: Oct 23, 2011
 *      Author: pjm2119
 */

#include "Coordinate.h"

Coordinate::Coordinate(float x, float y, float z) {
	this.x = x;
	this.y = y;
	this.z = z;
}

float Coordinate::xCoord()
{
	return x;
}

float Coordinate::yCoord()
{
	return y;
}

float Coordinate::zCoord()
{
	return z;
}

Coordinate::~Coordinate() {
	// TODO Auto-generated destructor stub
}

