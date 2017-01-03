#include "HuffmanEncoder.h"
#include "Tree.h"
#include <unordered_map>
#include <queue>
//#include <functional>

using namespace std;

// O(N) N is length of input
unordered_map<char, size_t> getFrequencies(const string& input) {
	unordered_map<char, size_t> freq;
	for (auto c : input) {
		if (freq.find(c) == freq.end())
			freq[c] = 1;
		else
			freq[c]++;
	}
	return freq;
}

// O(log(n))
unsigned int HuffmanEncoder::encodeString(const string & input, vector<char>& encoding) {
	auto frequencies = getFrequencies(input);	// Get a map with all characters and their frequencies

	auto compare = [](Tree* a, Tree *b) { return a->getWeight() > b->getWeight();}; // Define our own compare function for the priority queue to use. We define this so that the priority queue is a min queue
	priority_queue < Tree*, vector<Tree*>, decltype(compare)> priorQueue;

	// For each letter in frequencies
	for (auto it = frequencies.begin(); it != frequencies.end(); it++) {
		Tree* leaf = new Tree((*it).first, (*it).second);
		priorQueue.push(leaf);
	}
	while (priorQueue.size() > 1) {
		auto tree1 = priorQueue.top();
		priorQueue.pop();
		auto tree2 = priorQueue.top();
		priorQueue.pop();
		auto newTree = new Tree(tree1->getWeight() + tree2->getWeight(), tree1, tree2);
		priorQueue.push(newTree);
	}
	// Make this function return bitstring for decoding and create separate function for actually encoding the original string
	return 0;
}
