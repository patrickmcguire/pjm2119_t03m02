/*
 * TriangleMesh.h
 *
 *  Created on: Oct 27, 2011
 *      Author: pjm2119
 */


#include <string>
#include <fstream>

#ifndef TRIANGLEMESH_H_
#define TRIANGLEMESH_H_

class TriangleMesh {
public:
	TriangleMesh(char * filename);
	virtual ~TriangleMesh();
};

#endif /* TRIANGLEMESH_H_ */
