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
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/unordered_map.hpp>

using namespace std;

TriangleMesh::TriangleMesh(char * filename) {
	std::vector<Coordinate *> * coords = new std::vector<Coordinate *>;
	std::vector<NormalVector *> * normals = new std::vector<NormalVector *>;
	std::vector<Face *> * faces = new std::vector<Face *>;
	ifstream myfile;
	myfile.open(filename, ios::in);
	if(!myfile.is_open()) {
		throw 1;
	}
	readFromFile(myfile, coords, normals, faces);

	std::vector<Vertex *> * vertices = makeVertices(coords, normals);
	std::vector<Face *> * triangles = makeTriangles(faces, vertices);
	std::vector<HalfEdge *> * mesh = makeMesh(triangles,vertices);
	this.vertices = vertices;
	this.mesh = mesh;

}

void TriangleMesh::readFromFile(std::ifstream & input,
					std::vector<Coordinate *> * coords,
					std::vector<NormalVector *> * normals,
					std::vector<Face *> * indexFaces) {
	vector<string> lines;
	int i = 0;

	while(!input.eof()) {
		string * s = new string;
		std::getline(input,*s);
		lines.push_back(*s);
	}
	for(vector<string>::iterator it = lines.begin(); it != lines.end(); it++) {
		string line = *it;
		vector<string> tokens;
		vector<Face *> faceIndices;
		boost::algorithm::split(tokens,line,boost::algorithm::is_space());
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
				Face * f = (Face *) malloc(sizeof(Face));
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

std::vector<Vertex *> * TriangleMesh::makeVertices (std::vector<Coordinate *> * coords,
									std::vector<NormalVector *> * norms) {
	std::vector<Vertex *> * vertices = new vector<Vertex *>;
	for(unsigned int i = 0; i < norms->size(); i++) {
		Vertex * v = (Vertex *) malloc(sizeof(Vertex));
		v->normal = norms->at(i);
		v->point = coords->at(i);
		v->h = NULL;
		vertices->push_back(v);
	}
	return vertices;
}

/* I'm making the pretty bold assumption that everything is at least a valid polygon with three or more vertices */
std::vector<Face *> * TriangleMesh::makeTriangles(std::vector<Face *> * indexFaces,
													std::vector<Vertex *> * vertices) {
	std::vector<Face *> * triangles = new std::vector<Face *>;
	for(int i = 0; i < (int) indexFaces->size(); i++) {
		Face * f = indexFaces->at(i);
		int origin = f->vertices->at(0);
		int last = 0; //small hack, will get bumped back
		int current = f->vertices->at(1);
		for(int j = 2; j < (int) f->vertices->size(); j++) {
			last = current;
			current = indexFaces->at(i)->vertices->at(j);
			Face * triangle = (Face *) malloc(sizeof(Face));
			vector<int> * verts = new vector<int>;
			triangle->h = NULL;
			triangle->vertices = verts;

			Vertex * v1 = vertices->at(last);
			Vertex * v2 = vertices->at(current);

			verts->push_back(origin);
			if((v1->point->x >= v2->point->x) && (v1->point->y >= v2->point->y)) {
				verts->push_back(current);
				verts->push_back(last);
			} else {
				verts->push_back(last);
				verts->push_back(current);
			}
			triangles->push_back(triangle);
		}
	}
	return triangles;
}

std::vector<HalfEdge *> * TriangleMesh::makeMesh(std::vector<Face *> triangles,
												std::vector<Vertex *> vertices) {
	boost::unordered_map<string, HalfEdge *> map;
	std::vector<HalfEdge *> * edges = new std::vector<HalfEdge *>;
	/*Everything but the pair is easy*/
	for(std::vector<Face *>::iterator it = triangles.begin(); it != triangles.end(); it++) {
		HalfEdge * h1 = (HalfEdge *) malloc(sizeof(HalfEdge));
		HalfEdge * h2 = (HalfEdge *) malloc(sizeof(HalfEdge));
		HalfEdge * h3 = (HalfEdge *) malloc(sizeof(HalfEdge));

		Face * triangle = *it;
		int v1 = triangle->vertices->at(0);
		int v2 = triangle->vertices->at(1);
		int v3 = triangle->vertices->at(2);

		/* Corresponding with edges pointing to the three vertices */
		h1->v = v1;
		h2->v = v2;
		h3->v = v3;

		/* Set up the sequences */
		h1->next=h2;
		h2->next=h3;
		h3->next=h1;

		/* Put them in the map. Keys are weird, I know, but it's better than setting
		 * up a custom comparison function and overloading and ahhhh */
		string h1Vertices = v3 + "x" + v1;
		string h2Vertices = v1 + "x" + v2;
		string h3Vertices = v2 + "x" + v3;
		map[h1Vertices] = h1;
		map[h2Vertices] = h2;
		map[h3Vertices] = h3;

		/* Set pairs */
		string h1Rev = v1 + "x" + v3;
		string h2Rev = v2 + "x" + v1;
		string h3Rev = v3 + "x" + v2;
		if(map.count(h1Rev)) {
			HalfEdge * pair = map[h1Rev];
			pair->pair = h1;
			h1->pair = pair;
		}
		if(map.count(h2Rev)) {
			HalfEdge * pair = map[h2Rev];
			pair->pair = h2;
			h2->pair = pair;
		}
		if(map.count(h3Rev)) {
			HalfEdge * pair = map[h3Rev];
			pair->pair = h3;
			h3->pair = pair;
		}

		/* Set faces */
		h1->f = triangle;
		h2->f = triangle;
		h3->f = triangle;


		if(NULL == triangle->h) {
			triangle->h= h1;
		}
		if(NULL == vertices.at(v1)) {
			vertices.at(v1)->h = h1;
		}
		if(NULL == vertices.at(v2)) {
			vertices.at(v2)->h = h2;
		}
		if(NULL == vertices.at(v3)) {
			vertices.at(v3)->h = h3;
		}

		edges->push_back(h1);
		edges->push_back(h2);
		edges->push_back(h3);
	}
	return edges;
}




TriangleMesh::~TriangleMesh() {
	// TODO Auto-generated destructor stub
}

