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

	while(!myfile.eof())
	{
		char line[256];
		myfile.getline(line,256);
		vector<string> tokens;
		boost::algorithm::split(tokens,line,boost::algorithm::is_space());
		cout << tokens.size() << " " << tokens.at(0) << "\n";
		if(tokens.size() >= 3) {		{
			string first = tokens.at(0);
			if(first.compare("s")) {
				//do nothing
			} else if(first.compare("v")) {
				Coordinate * c = (Coordinate *) malloc(sizeof(Coordinate));
				sscanf(tokens.at(1).c_str(),"%f",&(c->x));
				sscanf(tokens.at(2).c_str(),"%f",&(c->y));
				sscanf(tokens.at(3).c_str(),"%f",&(c->z));
				coords.push_back(c);
			} else if(first.compare("vn")) {
				NormalVector * n = (NormalVector *) malloc(sizeof(NormalVector));
				sscanf(tokens.at(1).c_str(),"%f",&(n->x));
				sscanf(tokens.at(2).c_str(),"%f",&(n->y));
				sscanf(tokens.at(3).c_str(),"%f",&(n->z));
				normals.push_back(n);
			} else if(first.compare("f")) {
				vector<int> buffer;
				IndexFace * f = (IndexFace *) malloc(sizeof(IndexFace));
				for (unsigned int i = 1; i < tokens.size(); i++){
					int temp;
					sscanf(tokens.at(i).c_str(),"%d",&temp);
					buffer.push_back(temp);
				}
				f->numVertices = buffer.size();
				int * vertices = (int *) malloc(f->numVertices * sizeof(int));
				for (int i = 0; i < buffer.size(); i++) {
					vertices[i] = buffer.at(0);
				}
				f->vertices = vertices;
				faceIndexes.push_back(f);
			}
		}

	}
	vector<Vertex *> vertices;
	for(unsigned int i = 0; i < normals.size(); i++) {
		Vertex * v = (Vertex *) malloc(sizeof(Vertex));
		v->normal = normals.at(i);
		v->point = coords.at(i);
		vertices.push_back(v);
	}

	for(unsigned int i = 0; i < faces.size()){
	}


	vector< Face > triangles;
	for(vector< vector<int> >::iterator it = faces.begin(); it != faces.end(); it++)
	{
		int origin = it->at(0);
		int a,b;
		for(int i = 2; i < it->size(); i++)
		{
			int triangle[] = new int[3];
			triangle[0] = vertices.at(origin);
			triangle[1] = vertices.at(it->at(i-1));
			triangle[2] = vertices.at(it->at(i));
			triangles.push_back(triangle);
		}
	}

	HalfEdge edges[] = new HalfEdge[triangles.size() * 2];





	if(normals.size() != coords.size())
	{
		cout << "normals: " << normals.size << "\n";
		cout << "coords: " << coords.size << "\n";
		exit(-1);
	}



	// TODO Auto-generated constructor stub

}

TriangleMesh::~TriangleMesh() {
	// TODO Auto-generated destructor stub
}

