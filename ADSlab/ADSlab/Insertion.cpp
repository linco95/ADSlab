#include "Insertion.h"

InsertionSorter::InsertionSorter(){
}

InsertionSorter::~InsertionSorter(){
}

std::vector<int> InsertionSorter::sort(std::vector<int> input){ // O(n ^ 2)

	int sorted = 0;												// O(1)
	for (int i = sorted + 1; i < input.size(); i++) { // O(n) * O(n) = O(n^2)
		int index = i;											// O(1)
		int value = input.at(index);							// O(1)
		for (int k = sorted; k >= 0; k--) {							// O(n)
			input.erase(input.begin() + index);					// O(1)
			input.insert(input.begin() + index, input.at(k));	// O(1)
			auto test = input.at(k);							// O(1)
			if (test > value) {									// O(1)
				index--;										// O(1)
			}
			else {												// O(1)
				break;											// O(1)
			}
		}
		input.erase(input.begin() + index);						// O(1)
		input.insert(input.begin() + index, value);				// O(1)
		sorted++;												// O(1)
	}

	



	return input;
}
