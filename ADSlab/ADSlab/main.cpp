#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include "sebbes1.h"
#include "andreas1.h"
#include "Insertion.h"

using namespace std;

// Returns x vectors with size n
vector<vector<int>> createVectors(const int &x, const int &n) {
	vector<vector<int>> vectors;
	for (size_t i = 0; i < x; i++) {
		vector<int> vector;
		for (size_t j = 0; j < n; j++) {
			vector.push_back(rand() % 10);
		}
		vectors.push_back(vector);
	}
	return vectors;
}

float timeMeasure(const int &n) {
	// x = 100
	// n = 10, 25, 50, 75, 100, 125, 250, 325, 500
	vector<vector<int>> vectors;
	time_t before, after;
	float average;

	// Skapa x listor av storlek n
	vectors = createVectors(100, n);
	// Ta tid
	before = time(NULL);
	// Sortera listorna
	for (vector<int> x : vectors) {
		InsertionSorter::sort(x);
	}
	// Stoppa tiden
	after = time(NULL);
	// Räkna ut genomsnittstiden (dela tiden med x)
	average = (after - before) / 100.0f;
	// Returnera
	return average;
}


int main() {
	cout << "helloworld!\n";
	srand(time(NULL));
	vector<int> ourVector = { 8,2,3,3,5 };
	Sebbes1::BucketSort(ourVector);

	const int arrSize = 5;
	int arr[arrSize] = { 0, 1, 245, 3, 4 };
	int* sorted = BucketSorter::sort(arr, arrSize);
	cout << "Unsorted: ";
	BucketSorter::printArray(arr, arrSize);
	cout << endl << "Sorted: ";
	BucketSorter::printArray(sorted, arrSize);
	cout << endl;

	vector<int> result = InsertionSorter::sort(ourVector);

	for (int e : result) cout << e << " ";
	cout << endl;

	cout << timeMeasure(10) << " ";
	cout << timeMeasure(50) << " ";
	cout << timeMeasure(100) << " ";
	cout << timeMeasure(250) << " ";
	cout << timeMeasure(500) << " ";
	cout << timeMeasure(10000) << endl;

	// plot (10, 0) (50, 0) (100, 0.02) (250, 0.08) (500, 0.31) (1000, 1.25) 
	system("PAUSE");
	return 0;
}