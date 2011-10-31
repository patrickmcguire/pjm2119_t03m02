#include <iostream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TriangleMesh.h"

using namespace std;

int main(int argc, char * argv[]) {

	char * filename = NULL;
	if(argc > 1) {
		filename = argv[1];
	} else {
		cerr << "Please enter a filename";
		exit(-1);
	}
	TriangleMesh m(filename);
	char * flag = NULL;
	int index = NULL;
	if(argc > 2) {
		if(!strcmp(argv[2],"-ev")) {
			flag = argv[2];
		} else {
			cerr << "Only specify one argument unless flags are given";
			exit(-1);
		}
		sscanf(argv[3],"%d",&index);
	}

	std::vector<string> * query = m.query(index);
	for(std::vector<string>::iterator it = query->begin(); it != query->end(); it++) {
		cout << *it << "\n";
	}

	return 0;

/*
	main_t03m02 <OBJ_filename> -ev <vertex_index>
	Should be executed by your program when the –ev flag is given. Following the flag, one vertex index is
	specified. Your program output should be:
	<vertex_index>
	N
	<edge1_endpoint> <edge2_endpoint> ... <edgeN_endpoint>
	Where N is the number of edges, and <edgeX_endpoint> are the vertex indices of the edge endpoints
	different than the specified vertex index. The latter can be in any order. For example, referring to Figure
	2, the output of
	main_t03m02 <OBJ_filename> -ev 2
	Should be:
	2
	6
*/



}
