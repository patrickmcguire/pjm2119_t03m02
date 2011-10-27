/*
 * halfedge.h
 *
 *  Created on: Oct 27, 2011
 *      Author: pjm2119
 */

#ifndef HALFEDGE_H_
#define HALFEDGE_H_

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
} Vertex;

typedef struct Face {
	Vertex ** vertices;
	int numVertices;
} Face;

typedef struct IndexFace {
	int * vertices;
	int numVertices;
} IndexFace;

typedef struct HalfEdge {
	HalfEdge * pair;
	HalfEdge * next;
	Vertex * v;
	Face * f;
} HalfEdge;

#endif /* HALFEDGE_H_ */
