/*
 * Face.h
 *
 *  Created on: Oct 24, 2011
 *      Author: pjm
 */

#ifndef FACE_H_
#define FACE_H_

#include "Vertex.h"
#include "HalfEdge.h"

class Face {
	Vertex a,b,c;
	HalfEdge edgeA,edgeB,edgeC;
public:
	Face();
	Face(Vertex a, Vertex b, Vertex c)
	virtual ~Face();
};

#endif /* FACE_H_ */
