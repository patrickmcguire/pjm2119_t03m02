#include "NormalVector.h"
#include "Coordinate.h"
#include "Vertex.h"
#include "HalfEdge.h"
#include "Face.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <exception>

using namespace std;
using namespace boost;

int main(int argc, char * argv[])
{
	string line;
	vector<Coordinate> coords;
	vector<NormalVector> normals;
	vector<vector<int> > faces;

	if(argc == 1)
	{
		cerr << "Please include a filename";
		exit(-1);
	}

	string filename = argv[1];
	ifstream myfile (filename.c_str(), ios::in);
	if(!myfile.is_open())
	{
		cerr << "Error opening the file";
		exit(-1);
	}

	float x,y,z;

	while(!myfile.eof())
	{
		getline(myfile,line);
		vector<string> tokens;
		boost::algorithm::split(tokens,line,boost::algorithm::is_space());
		cout << tokens.size() << " " << tokens.at(0) << "\n";
		if(tokens.size() >= 3)
		{
			string first = tokens.at(0);
			if(first.compare("s"))
			{
				//do nothing
			}
			else if(first.compare("v"))
			{
				sscanf(tokens.at(1).c_str(),"%f",&x);
				sscanf(tokens.at(2).c_str(),"%f",&y);
				sscanf(tokens.at(3).c_str(),"%f",&z);
				Coordinate * c = new Coordinate(x,y,z);
				coords.push_back(*c);
			}
			else if(first.compare("vn"))
			{
				sscanf(tokens.at(1).c_str(),"%f",&x);
				sscanf(tokens.at(2).c_str(),"%f",&y);
				sscanf(tokens.at(3).c_str(),"%f",&z);
				NormalVector * n = new NormalVector(x,y,z);
				normals.push_back(*n);
			}
			else if(first.compare("f"))
			{
				vector<int> * face = new vector<int>();
				for (unsigned int i = 1; i < tokens.size(); i++)
				{
					int temp;
					sscanf(tokens.at(i).c_str(),"%d",&temp);
					face->push_back(temp);
				}
			faces.push_back(*face);
			}
		}

	}


	vector<Vertex> vertices;
	for(int i = 0; i < normals.size(); i++)
	{
		Vertex * v = new Vertex(coords.at(i),normals.at(i));
		vertices.push_back(*v);
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



	return 0;
}
