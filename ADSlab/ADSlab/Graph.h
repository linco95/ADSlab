#pragma once
#include <vector>
#include <list>

class Graph {
public:
	struct Node {
		std::vector<Node*> neighbours;
		bool visisted = false;
	};

	Graph();
	~Graph();

	std::vector<Node*> getFriends(const Node *node) const;


	void addNode(Node *node);
	void removeNode(const Node *node);

private:
	std::vector<Node*> nodes;
	
	std::list<std::list<size_t>> graph;
};