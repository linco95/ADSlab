#include <iostream>
#include "sebbes1.h"

using namespace std;

int main() {
	cout << "helloworld!\n";

	int ourArray[2] = { 0 };
	vector<int> ourVector = { 8,2,3,3,5 };
	vector<char> charVector = { '0','8','2','3','3','5' };

	Sebbes1::BucketSort(ourVector);
	//Sebbes1::BucketSortcharthatsucks(charVector);

	system("PAUSE");
	return 0;
}