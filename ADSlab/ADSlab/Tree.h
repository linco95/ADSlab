#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

class Tree {
public:
	Tree(int w, char c_);
	Tree(int w, Tree* t1, Tree* t2);
	~Tree();
	int getWeight() const;
	void printTree(std::vector<char>& bitString) const;
	void printTree(std::unordered_map<char, std::string>& charCodes) const;
private:
	void traverseTree(std::unordered_map<char, std::string>& charCodes, const std::string& currentPrefix) const;
	std::unique_ptr<Tree> left;
	std::unique_ptr<Tree> right;
	int weight;
	char c;
};