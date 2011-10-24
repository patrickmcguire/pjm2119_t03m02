/*
 * NormalVector.h
 *
 *  Created on: Oct 23, 2011
 *      Author: pjm2119
 */

#ifndef NORMALVECTOR_H_
#define NORMALVECTOR_H_

class NormalVector {
	float x,y,z;
public:
	NormalVector(float x, float y, float z);
	float xComponent();
	float yComponent();
	float zComponent();
	virtual ~NormalVector();
};

#endif /* NORMALVECTOR_H_ */
