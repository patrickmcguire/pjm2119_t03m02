#include "NormalVector.h"
#include "Coordinate.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;
using namespace boost;

int main(int argc, char * argv[])
{
	if(argc == 1)
	{
		cerr << "Please include a filename";
		exit(-1);
	}

	string filename = argv[1];
	ifstream myfile;
	myfile.open(filename.c_str(), ios::in);
	if(!myfile)
	{
		cerr << "Error opening the file";
		exit(-1);
	}

	string line;
	vector<Coordinate> coords;
	vector<NormalVector> normals;
	vector<vector<int> > faces;
	float x,y,z;

	while(!myfile.eof()) {
		getline(myfile,line);
		vector<string> tokens;
		boost::algorithm::split(tokens,line,boost::algorithm::is_space());
		string first = tokens.at(0);

		if(first.compare("v")) {
			sscanf(tokens.at(1).c_str(),"%f",&x);
			sscanf(tokens.at(2).c_str(),"%f",&y);
			sscanf(tokens.at(3).c_str(),"%f",&z);
			Coordinate c(x,y,z);
			coords.push_back(c);
		} else if(first.compare("vn")){
			sscanf(tokens.at(1).c_str(),"%f",&x);
			sscanf(tokens.at(2).c_str(),"%f",&y);
			sscanf(tokens.at(3).c_str(),"%f",&z);
			NormalVector n(x,y,z);
			normals.push_back(n);
		} else {
			vector<int> face;

			for (int i = 1; i < tokens.size(); i++) {

			}
			faces.push_back(face);
		}
	}
	return 0;
}
