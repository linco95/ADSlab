#pragma once

#include <vector>

class BucketSorter {
public:
	BucketSorter();
	~BucketSorter();


	static std::vector<int> sort(std::vector<int> v);

	static int* sort(int *inArr, const int& size);
	static void printArray(int *inArr, const int& size);

private:

};

