/*
 * halfedge.h
 *
 *  Created on: Oct 27, 2011
 *      Author: pjm2119
 */

#ifndef HALFEDGE_H_
#define HALFEDGE_H_

#include <vector>

typedef struct NormalVector {
	float x;
	float y;
	float z;
} NormalVector ;

typedef struct Coordinate {
	float x;
	float y;
	float z;
} Coordinate;

typedef struct Vertex {
	Coordinate * point;
	NormalVector * normal;
	HalfEdge * h;
} Vertex;

typedef struct Face {
	std::vector<int> * vertices;
	HalfEdge * h;
} Face;

typedef struct HalfEdge {
	HalfEdge * pair;
	HalfEdge * next;
	int v;
	Face * f;
} HalfEdge;

#endif /* HALFEDGE_H_ */
