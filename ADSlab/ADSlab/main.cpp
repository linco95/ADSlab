#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include "andreas1.h"
#include "Insertion.h"
#include "Graph.h"

using namespace std;

#pragma region timeSort
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


void testTimeInsertion() {
	vector<int> ourVector = { 8,2,3,3,5 };


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
}

#pragma endregion

void testGraph() {
	Graph g1(6);
	g1.setEdge(0, 1, 1);
	g1.setEdge(0, 2, 1);
	g1.setEdge(0, 3, 1);
	g1.setEdge(1, 3, 1);
	g1.setEdge(2, 4, 1);
	g1.setEdge(3, 4, 1);
	g1.setEdge(2, 5, 1);

	auto x = g1.getShortestPaths(3);
	for (auto y : x) {
		std::cout << "[" << y.index << ", " << y.dist << ", " << (y.dist % 2 ? "Enemy" : "Friend") << "]" << endl;

	}
}


void testHuff(string input) {

}

int main() {
	cout << "helloworld!\n";
	srand(time(NULL));

	//testTimeInsertion();

	//testGraph();

	testHuff("Hello world!");

	system("PAUSE");
	return 0;
}