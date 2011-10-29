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
	std::vector<HalfEdge *> * halfEdges;
} Vertex;

typedef struct Face {
	std::vector<Vertex *> * vertices;
	std::vector<HalfEdge *> * halfEdges;
} Face;

typedef struct IndexFace {
	std::vector<int> * vertices;
} IndexFace;

typedef struct HalfEdge {
	HalfEdge * pair;
	HalfEdge * next;
	Vertex * v;
	Face * f;
} HalfEdge;

#endif /* HALFEDGE_H_ */
