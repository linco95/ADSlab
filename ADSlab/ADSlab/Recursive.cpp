#include "Recursive.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
/*
* T(1) = 1
*/

int Recursive::dynamic(int input) {
	
}


int Recursive::recursive(int input) { // size n
	if (input == 1) {
		/*
		cout << "\t" << input << endl;
		*/
		return 1;
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