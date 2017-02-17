#include "Tree.h"
// DEBUG
#include <iostream>
#include <unordered_map>

using namespace std;

Tree::Tree(int w, char c_) : weight(w), left(), right(), c(c_) {}

Tree::Tree(int w, Tree* t1, Tree* t2) : weight(w), left(t1), right(t2) {}

Tree::~Tree() {
	left.reset();
	right.reset();
}

int Tree::getWeight() const {
	return weight;
}

void Tree::traverseTree(unordered_map<char, string>& charCodes, const std::string& currentPrefix) const {
	if (right && left) { // has children?
		(*left).traverseTree(charCodes, currentPrefix + "1");
		(*right).traverseTree(charCodes, currentPrefix + "0");
	}
	else { // is leaf
		charCodes[c] = currentPrefix;
	}
	
}

void Tree::printTree(unordered_map<char, string>& charCodes)  const {
	traverseTree(charCodes, "0");
}
/*
void Tree::printTree(std::vector<char>& bitString) const {
	if (bitString.empty()) { // At root?
		// onödigt
		bitString.push_back('0');
		cout << "0";
	}
	if (right && left) { // has children?
		bitString.push_back(' ');
		bitString.push_back('0');
		cout << " 0";
		(*left).printTree(bitString);
		bitString.push_back(' ');
		bitString.push_back('1');
		cout << " 1";
		(*right).printTree(bitString);
	}
	else { // is leaf
		bitString.push_back(' ');
		bitString.push_back(':');
		bitString.push_back(' ');
		bitString.push_back(c); // 0 1 1 : c \n
		bitString.push_back('\n');
		cout << ": " << c << endl;
	}
}
*/
/*
Tree* tree1 = new Tree(asdasd);
Tree* tree2 = new Tree(asdasd);
Tree* tree3 = new Tree(tree1, tree2);

delete tree3;
*/
