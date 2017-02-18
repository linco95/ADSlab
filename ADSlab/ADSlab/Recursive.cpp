#include "Recursive.h"
#include <unordered_map>
#include <iostream>
#include <math.h>
using namespace std;


static unordered_map<int, int> times;

int retrieve(int n, bool& ok) {
	auto item = times.find(n);
	ok = item != times.end();
	if (!ok) return -1;
	return item->second;
}

int Recursive::dynamic(int input) {
	// Top down 
	if (input == 1) {
		return 1;
	}

	bool ok;
	int time = retrieve(input, ok);
	if (!ok) {
		time = dynamic(input - 1) + dynamic(ceil(input / 2)) + input;
		times[input] = time;
	}
	return time;
}


int Recursive::recursive(int input) { // size n
	if (input == 1) {
		/*
		cout << "\t" << input << endl;
		*/
		return 1;
		// T(1) = 1
	}
	else {
		/*
		cout << "\t";
		for (int i = 1; i <= input; i++) {
			cout << i << " ";
		}
		cout << endl;
		*/
		// * T(n) = T(n-1) + T(n/2) + n | O(n2log(n))
		return recursive(input - 1) + recursive(ceil(input / 2)) + input;
	}
}