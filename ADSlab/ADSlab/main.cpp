#include <iostream>
#include "sebbes1.h"
#include "andreas1.h"

using namespace std;

int main() {
	cout << "helloworld!\n";

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

	vector<int> result = BucketSorter::sort(ourVector);

	for (int e : result) cout << e << " ";
	cout << endl;


	system("PAUSE");
	return 0;
}