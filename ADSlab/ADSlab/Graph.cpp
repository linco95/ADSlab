#include "Graph.h"
#include <queue>
#include <list>
#include <set>
using namespace std;


Graph::Graph(const int& n = 0) {
	numberOfNodes = n;
	if (n == 0) p = NULL;
	else {
		p = new datatype*[n]; // Allocate n memoryslots of datatypeptr
		for (int i = 0; i < n; i++) {
			p[i] = new datatype[n]; // Allocate an array with n datatype
			for (int j = 0; j < n; j++) {
				p[i][j] = 0; // initiate value to 0
			}
		}
	}
}
Graph::~Graph() {

	/*
	TODO: deallocate p
	if (n == 0) p = NULL;
	else {
		p = new datatype*[n]; // Allocate n memoryslots of datatypeptr
		for (int i = 0; i < n; i++) {
			p[i] = new datatype[n]; // Allocate an array with n datatype
			for (int j = 0; j < n; j++) {
				p[i][j] = 0; // initiate value to 0
			}
		}
	}*/
}

bool Graph::isEdge(const int & i = 0, const int & j = 0) const {
	return p[i][j] != 0;
}

queue<Graph::datatype> Graph::getNeigbhours(int index) const {
	queue<Graph::datatype> neig;
	for (int i = 0; i < numberOfNodes; i++) {
		if (isEdge(index, i)) neig.push(i);
	}
	return neig;
}

void Graph::setEdge(const int & i, const int &j, const datatype &x) {
	p[i][j] = x;
	p[j][i] = x;
}

list<Graph::neighbourDist> Graph::getShortestPaths(const int &A) const {

	queue<neighbourDist> visitUs;
	set<int> visited;
	list<neighbourDist> determined;
	// Insert startvalue into queue
	visitUs.push(neighbourDist(A, 0));

	while (!visitUs.empty()) {
		auto nodeDist = visitUs.front();
		visitUs.pop();
		if (visited.find(nodeDist.index) == visited.end()) {
			visited.insert(nodeDist.index);
			determined.push_back(nodeDist);

			auto neigh = getNeigbhours(nodeDist.index);

			while (!neigh.empty()) {
				neighbourDist data;
				data.index = neigh.front();
				neigh.pop();
				data.dist = nodeDist.dist + 1;
				visitUs.push(data);
			}
		}
	}
	return determined;
}



/*	list<datatype> marked;
	marked.push_back(v);
	q.push(v);
	while (!q.empty()) {
		datatype t = q.back;
		q.pop();
		// process t
		for (int index : getNeigbhours(t)) {
			if (!marked.contains(g)) {
				marked.insert(g);
				q.enqueue(g);
			}
		}
	}
	}*/