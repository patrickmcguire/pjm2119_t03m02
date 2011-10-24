/*
 * Vertex.h
 *
 *  Created on: Oct 23, 2011
 *      Author: pjm2119
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "NormalVector.h"
#include "Coordinate.h"

class Vertex {

public:
	Coordinate p;
	NormalVector n;
	Vertex(Coordinate p, NormalVector n);
	Vertex();
	virtual ~Vertex();
};

#endif /* VERTEX_H_ */
