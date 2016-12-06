#include "Graph.h"


void initializeAdjMatrix(const int& n, Graph::datatypeptr* p) {
	if (n == 0) p = NULL;
	else {

		p = new Graph::datatypeptr[n]; // Allocate n memoryslots of datatypeptr
		for (int i = 0; i < n; i++) {
			p[i] = new Graph::datatype[n]; // Allocate an array with n datatype
			for (int j = 0; j < n; j++) {
				p[i][j] = 0; // initiate value to 0
			}
		}
	}
}

Graph::Graph(const int& n = 0) {
	numberOfNodes = n;
	initializeAdjMatrix(n, p);
}
Graph::~Graph() {

}

bool Graph::isEdge(const int & i = 0, const int & j = 0) const{

	return p[i][j] != 0;
}

void Graph::setEdge(const int & i, const int &j, const datatype &x){
	p[i][j] = x;
}
