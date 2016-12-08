#include "Graph.h"
#include <queue>
#include <list>
#include <set>
using namespace std;

template<typename T>
void initializeMatrix(const int& size, T** matrix) {
	if (size == 0) p = NULL;
	else {
		matrix = new T*[size]; // Allocate n memoryslots of datatypeptr
		for (int i = 0; i < size; i++) {
			matrix[i] = new T[n]; // Allocate an array with n datatype
			for (int j = 0; j < size; j++) {
				matrix[i][j] = 0; // initiate value to 0
			}
		}
	}
}

Graph::Graph(const int& n = 0) {
	numberOfNodes = n;
	initializeMatrix<datatype>(n, p);
}
Graph::~Graph() {

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
}

list<Graph::datatype> Graph::getShortestPaths(const int &A) const {
	struct neighbourDist {
		int index;
		int dist;
		neighbourDist() {}

		neighbourDist(int i, int d) {
			index = i;
			dist = d;
		}
		bool operator==(const neighbourDist &other) {
			return index == other.index;
		}
		bool operator!=(const neighbourDist &other) {
			return !(*this == other);
		}
		bool operator<(const neighbourDist &other) {
			return dist < other.dist;
		}
		bool operator>(const neighbourDist &other) {
			return dist > other.dist;
		}
		bool operator>=(const neighbourDist &other) {
			return dist >= other.dist;
		}
		bool operator>=(const neighbourDist &other) {
			return dist >= other.dist;
		}
	};
	
	queue<neighbourDist> visitUs;
	set<int> visited;
	list<neighbourDist> determined;

	visitUs.push(neighbourDist(A, 0));
	visited.insert(A);

	while (!visitUs.empty()) {
		auto nodeDist = visitUs.back();
		visitUs.pop();
		if (*(visited.find(nodeDist.index)) < 0) continue;
		visited.insert(nodeDist.index);

		auto neigh = getNeigbhours(nodeDist.index);
		determined.push_back(nodeDist);

		while (neigh.empty()) {
			neighbourDist data;
			data.index = neigh.back();
			neigh.pop();
			data.dist = nodeDist.dist + 1;
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