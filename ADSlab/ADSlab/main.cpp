#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "andreas1.h"
#include "Insertion.h"
#include "HuffmanEncoder.h"
#include "Graph.h"
#include <thread>
#include <future>
#include <unordered_map>
#include "Recursive.h"
#include <chrono>

using namespace std;

/*template<typename T>
void swap(T& a, T&b) {
	auto temp = a;
	a = b;
	b = temp;
}
*/

// Implementation of https://www.youtube.com/watch?v=aQiWF4E8flQ&t=109s
vector<int> quicksort(vector<int> arr) {
	if (arr.size() <= 1) return arr;

	int pivot = arr.size() - 1;
	int wall = 0;
	int curEl = 0;
	while (pivot != curEl) {
		if (arr.at(curEl) < arr.at(pivot)){
			swap(arr.at(curEl), arr.at(wall));
			wall++;
		}
		curEl++;
	}
	swap(arr.at(pivot), arr.at(wall));
	future<vector<int>> first = async(quicksort, vector<int>(arr.begin(), arr.begin() + wall));
	future<vector<int>> second = async(quicksort, vector<int>(arr.begin() + wall, arr.end()));
	vector<int> vec1 = first.get();
	vector<int> vec2 = second.get();
	vec1.insert(vec1.end(), vec2.begin(), vec2.end()); // Concatencate vectors

	return vec1;
}




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
		std::cout << "[" << y.first<< ", " << y.second << ", " << (y.second % 2 ? "Enemy" : "Friend") << "]" << endl;

	}
}


void testHuff(string input) {
	unordered_map<char, std::string> charCodes;
	cout << "HUFFMAN:" << endl;
	HuffmanEncoder::encodeString(input, charCodes);
	
	for (auto it = charCodes.begin(); it != charCodes.end(); it++) {
		cout << it->first << ", " << it->second << endl;
		
	}
}

void testTCalc(int n) {
	cout << "RECURSIVE ****************\n";


	auto begin = std::chrono::high_resolution_clock::now();
	// code to benchmark
	cout << "T(" << n << ") = " << Recursive::recursive(n) << endl;
	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Recursive: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;

	begin = std::chrono::high_resolution_clock::now();
	// code to benchmark
	cout << "T(" << n << ") = " << Recursive::dynamic(n) << endl;
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Dynamic: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
}

int main() {
	cout << "helloworld!\n";
	srand(time(NULL));
	time_t before = time(NULL);
	auto sorted = quicksort(vector<int>({ -1712, 2163 }));
	time_t after = time(NULL);
	//testTimeInsertion();
	for (auto x : sorted) {
		cout << x << ", ";
	}
	cout << endl << difftime(before, after) << endl;
	//testGraph();

	testHuff("aaaaaabbb");

	testTCalc(pow(2, 2));
	
	system("PAUSE");
	return 0;
}