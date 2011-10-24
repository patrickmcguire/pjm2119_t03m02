/*
 * Coordinate.cpp
 *
 *  Created on: Oct 23, 2011
 *      Author: pjm2119
 */

#include "Coordinate.h"

Coordinate::Coordinate(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Coordinate::Coordinate()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
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

