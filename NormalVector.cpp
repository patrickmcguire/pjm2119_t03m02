/*
 * NormalVector.cpp
 *
 *  Created on: Oct 23, 2011
 *      Author: pjm2119
 */

#include "NormalVector.h"

NormalVector::NormalVector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

NormalVector::NormalVector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

float NormalVector::xComponent()
{
	return x;
}

float NormalVector::yComponent()
{
	return y;
}

float NormalVector::zComponent()
{
	return z;
}
NormalVector::~NormalVector() {
	// TODO Auto-generated destructor stub
}

