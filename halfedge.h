/*
 * halfedge.h
 *
 *  Created on: Oct 27, 2011
 *      Author: pjm2119
 */

#ifndef HALFEDGE_H_
#define HALFEDGE_H_

typedef struct _NormalVector {
	float x;
	float y;
	float z;
} NormalVector ;

typedef struct _Coordinate {
	float x;
	float y;
	float z;
} Coordinate;

typedef struct _Vertex {
	Coordinate * point;
	NormalVector * normal;
} Vertex;

typedef struct _Face {
	Vertex ** vertices;
	int numVertices;
} Face;



#endif /* HALFEDGE_H_ */
