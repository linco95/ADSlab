#include "Insertion.h"

InsertionSorter::InsertionSorter(){
}

InsertionSorter::~InsertionSorter(){
}


std::vector<int> InsertionSorter::sort(std::vector<int> input){

	int sorted = 0;
	for (int i = sorted + 1; i < input.size(); i++) {
		int index = i;
		int value = input.at(index);
		for (int k = sorted; k >= 0; k--) {
			input.erase(input.begin() + index);
			input.insert(input.begin() + index, input.at(k));
			auto test = input.at(k);
			if (test > value) {
				index--;
			}
			else {
				break;
			}
		}
		input.erase(input.begin() + index);
		input.insert(input.begin() + index, value);
	}



	return input;
}
