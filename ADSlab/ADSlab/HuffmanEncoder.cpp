#include "HuffmanEncoder.h"
#include "Tree.h"
#include <unordered_map>
#include <queue>
#include <assert.h>

//#include <functional>

using namespace std;

// Create type minQueue
auto compare = [](Tree* a, Tree *b) { return a->getWeight() > b->getWeight(); }; // Define our own compare function for the priority queue to use. We define this so that the priority queue is a min queue
typedef priority_queue < Tree*, vector<Tree*>, decltype(compare)> minQueue;

// O(n) n is length of input string
unordered_map<char, size_t> getFrequencies(const string& input) {	// o(n)
	unordered_map<char, size_t> freq;					// O(1)
	for (auto c : input) {								// O(n)
		if (freq.find(c) == freq.end())						// O(1)
			freq[c] = 1;									// O(1)
		else												// O(1)
			freq[c]++;										// O(1)
	}
	return freq;
}



// O(n) + O(n) + O(n) = O(n)
void HuffmanEncoder::encodeString(const string & input, std::unordered_map<char, std::string>& charCodes) {
	assert(input.size() > 0);															// O(1)
	// Get a map with all characters and their frequencies
	auto frequencies = getFrequencies(input);											// O(n)
	assert(frequencies.size() > 1);														// O(1)

	minQueue priorQueue(compare);														// O(1)

	// For each letter in frequencies
	for (auto it = frequencies.begin(); it != frequencies.end(); it++) {				// O(n)
		Tree* leaf = new Tree((*it).second, (*it).first);								// O(1)
		priorQueue.push(leaf);															// O(1)
	}
	while (priorQueue.size() > 1) {														// O(n)
		auto tree1 = priorQueue.top();													// O(1)
		priorQueue.pop();																// O(1)
		auto tree2 = priorQueue.top();													// O(1)
		priorQueue.pop();																// O(1)
		auto newTree = new Tree(tree1->getWeight() + tree2->getWeight(), tree1, tree2); // O(1)
		priorQueue.push(newTree);														// O(1)
	}

	priorQueue.top()->printTree(charCodes);												// O(n)?
	// Make this function return bitstring for decoding and create separate function for actually encoding the original string
	delete priorQueue.top();															// O(1)
}
