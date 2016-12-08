#pragma once
#include <list>
#include <queue>

class Graph {
public:
	typedef int datatype;
	typedef datatype* datatypeptr;

	Graph(const int &n);
	~Graph();

	bool isEdge(const int& i, const int& j) const;
	void setEdge(const int& i, const int& j, const datatype &x);

	// Will return an numberOfNodes^2 matrix with the shortest paths between the nodes
	std::list<datatype> getShortestPaths(const int &A) const;
	std::queue<Graph::datatype> Graph::getNeigbhours(int v) const;

private:
	datatypeptr *p;
	int numberOfNodes;
};