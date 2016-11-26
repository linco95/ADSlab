#pragma once
#include <vector>

class Graph {
public:
	struct Node {
		std::vector<Node> neighbours;
		bool isFriend;
	};

	Graph();
	~Graph();

	bool isFriend(const Node &node) const;

	Node& addNode(Node node);
	void removeNode(const Node &node);

private:
	std::vector<Node> nodes;
};