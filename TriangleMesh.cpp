/*
 * TriangleMesh.cpp
 *
 *  Created on: Oct 27, 2011
 *      Author: pjm2119
 */

#include "TriangleMesh.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;

TriangleMesh::TriangleMesh(char * filename) {

	ifstream myfile (filename, ios::in);
	if(!myfile.is_open())
	{
		cerr << "Error opening the file";
		exit(-1);
	}
	std::vector<Coordinate *> * coords = new std::vector<Coordinate *>;
	std::vector<NormalVector *> * normals = new std::vector<NormalVector *>;
	std::vector<IndexFace *> * indexFaces = new std::vector<IndexFace *>;
	readFromFile(myfile, coords, normals, indexFaces);

	std::vector<Vertex *> * vertices = makeVertices(coords, normals, vertices);
	std::vector<Face *> * triangles = makeTriangles(indexFaces, vertices);


}

void readFromFile(std::ifstream & input,
					std::vector<Coordinate *> * coords,
					std::vector<NormalVector *> * normals,
					std::vector<IndexFace *> * indexFaces) {
	while(!input.eof())
	{
		char line[256];
		input.getline(line,256);
		vector<string> tokens;
		vector<IndexFace *> faceIndices;
		boost::algorithm::split(tokens,line,boost::algorithm::is_space());
		cout << tokens.size() << " " << tokens.at(0) << "\n";
		if(tokens.size() >= 3) {
			string first = tokens.at(0);
			if(first.compare("s")) {
				//do nothing
			} else if(first.compare("v")) {
				Coordinate * c = (Coordinate *) malloc(sizeof(Coordinate));
				sscanf(tokens.at(1).c_str(),"%f",&(c->x));
				sscanf(tokens.at(2).c_str(),"%f",&(c->y));
				sscanf(tokens.at(3).c_str(),"%f",&(c->z));
				coords->push_back(c);
			} else if(first.compare("vn")) {
				NormalVector * n = (NormalVector *) malloc(sizeof(NormalVector));
				sscanf(tokens.at(1).c_str(),"%f",&(n->x));
				sscanf(tokens.at(2).c_str(),"%f",&(n->y));
				sscanf(tokens.at(3).c_str(),"%f",&(n->z));
				normals->push_back(n);
			} else if(first.compare("f")) {
				vector<int> * buffer = new vector<int>(0);
				IndexFace * f = (IndexFace *) malloc(sizeof(IndexFace));
				for (unsigned int i = 1; i < tokens.size(); i++){
					int temp;
					sscanf(tokens.at(i).c_str(),"%d",&temp);
					buffer->push_back(temp);
				}
				f->vertices = buffer;
				faceIndices.push_back(f);
			}
		}
	}
}

std::vector<Vertex *> * makeVertices (std::vector<Coordinate *> * coords,
									std::vector<NormalVector *> * norms) {
	std::vector<Vertex *> * vertices = new vector<Vertex>;
	for(unsigned int i = 0; i < norms->size(); i++) {
		Vertex * v = (Vertex *) malloc(sizeof(Vertex));
		v->normal = norms->at(i);
		v->point = coords->at(i);
		vertices->push_back(v);
	}
	return vertices;
}

void triangularize(std::vector<Face *> & polygons,
					std::vector<Face *> & triangles) {
	for(vector< vector<int> >::iterator it = polygons.begin(); it != polygons.end(); it++) {
		int origin = it->at(0);
		int a,b;
		for(int i = 2; i < it->size(); i++) {
		}
	}

	HalfEdge edges[] = new HalfEdge[triangles.size() * 2];



	// TODO Auto-generated constructor stub

}

TriangleMesh::~TriangleMesh() {
	// TODO Auto-generated destructor stub
}

