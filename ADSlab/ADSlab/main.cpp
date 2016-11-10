#include <iostream>
#include "sebbes1.h"
#include "andreas1.h"

using namespace std;

int main() {
	cout << "helloworld!\n";

	int ourArray[2] = { 0 };
	vector<int> ourVector = { 8,2,3,3,5 };
	vector<char> charVector = { '0','8','2','3','3','5' };

	Sebbes1::BucketSort(ourVector);
	//Sebbes1::BucketSortcharthatsucks(charVector);

	const int arrSize = 5;
	int arr[arrSize] = { 0, 1, 245, 3, 4 };
	int* sorted = BucketSorter::sort(arr, arrSize);
	cout << "Unsorted: ";
	BucketSorter::printArray(arr, arrSize);
	cout << endl << "Sorted: ";
	BucketSorter::printArray(sorted, arrSize);
	cout << endl;



	system("PAUSE");
	return 0;
}