/*
 * HalfEdge.h
 *
 *  Created on: Oct 24, 2011
 *      Author: pjm
 */

#ifndef HALFEDGE_H_
#define HALFEDGE_H_

#include "Vertex.h"

class HalfEdge {
	Vertex v;
	HalfEdge pair, next;
	Face f;
public:
	HalfEdge();
	HalfEdge(Vertex v, HalfEdge pair, HalfEdge next, Face f);
	virtual ~HalfEdge();


};

#endif /* HALFEDGE_H_ */
