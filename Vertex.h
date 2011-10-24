/*
 * Vertex.h
 *
 *  Created on: Oct 23, 2011
 *      Author: pjm2119
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "Coordinate.h"

class Vertex {
	Coordinate p;
	NormalVector n;
public:
	Vertex(Coordinate p, NormalVector n);
	virtual ~Vertex();
};

#endif /* VERTEX_H_ */
