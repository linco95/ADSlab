#pragma once

#include <vector>

class InsertionSorter {
public:
	InsertionSorter();
	~InsertionSorter();

	static std::vector<int> sort(std::vector<int> input);
};