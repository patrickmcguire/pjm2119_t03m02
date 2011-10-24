/*
 * Coordinate.h
 *
 *  Created on: Oct 23, 2011
 *      Author: pjm2119
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

class Coordinate {
	float x,y,z;
public:
	Coordinate(float x, float y, float z);
	float xCoord();
	float yCoord();
	float zCoord();
	virtual ~Coordinate();
};

#endif /* COORDINATE_H_ */
