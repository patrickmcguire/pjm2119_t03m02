#include <iostream>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include "TriangleMesh.h"

using namespace std;

int main(int argc, char * argv[]) {

	char * filename;
	if(argc > 1) {
		filename = argv[0];
	} else {
		cerr << "Please enter a filename";
		exit(-1);
	}
	TriangleMesh m(filename);
	return 0;
}
