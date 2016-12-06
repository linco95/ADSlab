#pragma once
#include <array>

class Graph {
public:
	typedef int datatype;
	typedef datatype* datatypeptr;

	Graph(const int &n);
	~Graph();

	bool isEdge(const int& i, const int& j) const;
	void setEdge(const int& i, const int& j, const datatype &x);

private:
	datatypeptr *p;
	int numberOfNodes;
};