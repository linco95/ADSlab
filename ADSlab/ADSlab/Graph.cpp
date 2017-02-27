#include "Graph.h"
#include <queue>
#include <map>
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

queue<Graph::datatype> Graph::getNeigbhours(int index) const {	// O(n)
	queue<Graph::datatype> neig;							// O(1)
	for (int i = 0; i < numberOfNodes; i++) {				// O(n)
		if (isEdge(index, i)) neig.push(i);
	}
	return neig;
}

void Graph::setEdge(const int & i, const int &j, const datatype &x) {
	p[i][j] = x;
	p[j][i] = x;
}

map<int, int> Graph::getShortestPaths(const int &A) const { // O(n) * O(n) = O(n^2)?

	queue<neighbourDist> visitUs;										// O(1)
	map<int, int> visited;												// O(1)
	// Insert startvalue into queue
	visitUs.push(neighbourDist(A, 0));									// O(1)

	while (!visitUs.empty()) {											// O(n) * O(n) = O(n^2)?
		auto nodeDist = visitUs.front();								// O(1)
		visitUs.pop();													// O(1)
		if (visited.find(nodeDist.index) == visited.end()) {			// O(log(n))
			visited[nodeDist.index] = nodeDist.dist;					// O(1)

			auto neigh = getNeigbhours(nodeDist.index);					// O(n)

			while (!neigh.empty()) {									// O(n)
				neighbourDist data;										// O(1)
				data.index = neigh.front();								// O(1)
				neigh.pop();											// O(1)
				data.dist = nodeDist.dist + 1;							// O(1)
				visitUs.push(data);										// O(1)
			}
		}
	}
	return visited;
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