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
	void readFromFile(std::ifstream & input,
					std::vector<Coordinate *> * coords,
					std::vector<NormalVector *> * normals,
					std::vector<IndexFace *> * indexFaces);
	std::vector<Vertex *> * makeVertices (std::vector<Coordinate *> * coords,
										std::vector<NormalVector *> * norms);
	std::vector<IndexFace *> *  makeTriangles(std::vector<IndexFace *> * indexFaces,
										std::vector<Vertex *> * vertices);
public:
	TriangleMesh(char * filename);
	virtual ~TriangleMesh();
};

#endif /* TRIANGLEMESH_H_ */
