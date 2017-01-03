#include "Tree.h"

// DEBUG
#include <iostream>

using namespace std;

Tree::Tree(int w, char c_) : weight(w), c(c_) {}

Tree::Tree(int w, Tree* t1, Tree* t2) : weight(w), left(t1), right(t2) {}

Tree::~Tree() {
	left.reset();
	right.reset();
}

inline int Tree::getWeight() const {
	return weight;
}

void Tree::printTree(std::vector<char>& bitString) const {
	if (bitString.empty()) {
		// onödigt\
		bitString.push_back('0');
		bitString.push_back(' ');
		cout << "0 ";
	}
	else {
		bitString.push_back(' ');
		cout << " ";
	}
	if (right && left) {
		bitString.push_back('0');
		cout << "0";
		(*left).printTree(bitString);
		bitString.push_back('1');
		cout << "0";
		(*right).printTree(bitString);
	}
	else {
		bitString.push_back(':');
		bitString.push_back(' ');
		bitString.push_back(c); // 0 1 1 : c \n
		bitString.push_back('\n');
		cout << ": " << c << endl;
	}
}

/*
Tree* tree1 = new Tree(asdasd);
Tree* tree2 = new Tree(asdasd);
Tree* tree3 = new Tree(tree1, tree2);

delete tree3;
*/
