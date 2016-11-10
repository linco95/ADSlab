#include "andreas1.h"

#include <iostream>

using namespace std;

BucketSorter::BucketSorter() {}

// Return largest value in the array
int max(int *inArr, int size) {
	int maxVal = *inArr;
	for (int i = 1; i < size; i++) {
		if (*(inArr + i) > maxVal) 
			maxVal = *(inArr + i);
	}
	return maxVal;
}

// Sort an integer array with bucket sort
int* BucketSorter::sort(int *inArr, const int &size) {
	// k is the highest value in the array
	const int k = max(inArr, size);
	const int sizeOfW = k + 1;

	// w is allocated to an empty array of k + 1 elements;
	int *w = new int[sizeOfW];
	// initialize the array to 0
	for (int i = 0; i < sizeOfW; i++)
		*(w + i) = 0;

	// Count how many times each number appears
	for (int i = 0; i < size; i++) {
		int index = *(inArr + i);
		*(w + index) += 1;
	}

	// Allocate an array of size 'size'
	int *resultArr = new int[size];

	// Print each item the amount of times it appears in the list, in order
	for (int i = 0, j = 0; i < sizeOfW; i++) {
		while (*(w + i) > 0) {
			*(resultArr + j) = i;
			j++;
			*(w + i) -= 1;
		}
	}

	return resultArr;
}


void BucketSorter::printArray(int *inArr, const int& size) {
	for (int i = 0; i < size - 1; i++) {
		cout << *(inArr + i) << ", ";
	}
	cout << *(inArr + size - 1);
}

BucketSorter::~BucketSorter() {}