/*
 * NormalVector.cpp
 *
 *  Created on: Oct 23, 2011
 *      Author: pjm2119
 */

#include "NormalVector.h"

NormalVector::NormalVector(float x, float y, float z)
{
	this.x = x;
	this.y = y;
	this.z = z;
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

