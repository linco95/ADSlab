#pragma once

#include <vector>
#include <memory>

class Tree {
public:
	Tree(int w, char c_);
	Tree(int w, Tree* t1, Tree* t2);
	~Tree();
	int getWeight() const;
	void printTree(std::vector<char>& bitString) const;
private:
	std::unique_ptr<Tree> left;
	std::unique_ptr<Tree> right;
	int weight;
	char c;
};