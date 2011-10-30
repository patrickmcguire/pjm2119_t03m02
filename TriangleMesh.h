/*
 * TriangleMesh.h
 *
 *  Created on: Oct 27, 2011
 *      Author: pjm2119
 */


#include <string>
#include <fstream>
#include <vector>
#include "halfedge.h"

#ifndef TRIANGLEMESH_H_
#define TRIANGLEMESH_H_

class TriangleMesh {
private:
	std::vector<Vertex *> vertices;
	std::vector<HalfEdge *> mesh;
	std::vector<Face *> triangles;
	void readFromFile(std::ifstream & input,
					std::vector<Coordinate *> * coords,
					std::vector<NormalVector *> * normals,
					std::vector<Face *> * indexFaces);
	std::vector<Vertex *> * makeVertices (std::vector<Coordinate *> * coords,
										std::vector<NormalVector *> * norms);
	std::vector<Face *> *  makeTriangles(std::vector<Face *> * indexFaces,
										std::vector<Vertex *> * vertices);
	std::vector<HalfEdge *> * makeMesh(std::vector<Face *> * triangles,
										std::vector<Vertex *> * vertices);
public:
	std::vector<std::string> * query(int v);
	TriangleMesh(char * filename);
	virtual ~TriangleMesh();
};

#endif /* TRIANGLEMESH_H_ */
