#include "Graph.h"


Graph::Graph() {

}
Graph::~Graph() {

}

std::vector<Graph::Node*> Graph::getFriends(const Node *node) const{
	std::vector<Node*> herro;
	return herro; // From teh utter side (WE HAVE COOKIES!)
}


void Graph::addNode(Node *node) {
	nodes.push_back(node);
}
void Graph::removeNode(const Node *node) {
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		auto node2 = *it;
		if (node2 == node)
		{
			nodes.erase(it);
			break;
		}
	}
}