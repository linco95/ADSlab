#include "Recursive.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
/*
* T(n) = T(n-1) + T(n/2) + n | O(n2log(n))
* T(1) = 1
*/


void Recursive::recursive(string input) { // size n
	if (input.size() == 1) {
		cout << "\t" << input << endl;
	}
	else {
		recursive(input.substr(input.size() - 1));
		recursive(input.substr(ceil(input.size() / 2)));
		cout << "\t";
		for (auto c : input) {
			cout << c << " ";
		}
		cout << endl;
	}
}