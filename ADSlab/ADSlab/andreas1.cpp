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


/********************************************************************************/

// Returns max value of the vector
int max(std::vector<int> vec) {		// O(1) + O(n) * O(1) = O(n)
	int max = vec.at(0);		// O(1)
	for (int e : vec) {			// O(n)
		if (e > max) max = e;		// O(1)
	}
	return max;
}

std::vector<int> BucketSorter::sort(vector<int> v) {	// O(n + k)
	int k = max(v);									// O(1)
	
	// Create empty vector w
	vector<int> w;									// O(1)
	// Initialize it to 0 at every element
	for (int i = 0; i < k + 1; i++) w.push_back(0);	// O(k)

	// Count how many time each number appears in v
	for (int e : v)									// O(n)
		w.at(e)+=1;										// O(1)

	// Add each number correct amount of times in the v array and return it
	for (int i = 0, j = 0 ; i < w.size(); i++) {	// O(k)
		while (w.at(i) > 0) {						// O(n)
			v.at(j) = i;
			j++;
			w.at(i) -= 1;
		}
	}

	return v;
}
