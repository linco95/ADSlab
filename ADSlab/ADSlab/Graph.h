#pragma once
#include <list>
#include <queue>

class Graph {
public:
	typedef int datatype;
	typedef datatype* datatypeptr;

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

	};

	Graph(const int &n);
	~Graph();

	bool isEdge(const int& i, const int& j) const;
	void setEdge(const int& i, const int& j, const datatype &x);

	// Will return an numberOfNodes^2 matrix with the shortest paths between the nodes
	std::list<neighbourDist> getShortestPaths(const int &A) const;
	std::queue<Graph::datatype> Graph::getNeigbhours(int v) const;

private:
	datatypeptr *p;
	int numberOfNodes;
};