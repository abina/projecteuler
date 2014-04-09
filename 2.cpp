/*
	num & 1 to get the last bit
*/
#include <iostream>

using namespace std;

int main() {

	int sum = 0;
	int a = 1;
	int b = 2;
	int c = b;

	do {
		if ((c & 1) == 0) {
			sum += c;
		}
		c = a + b;
		a = b;
		b = c;

	} while (c <= 4000000);

	cout << sum << endl;	
	return 0;
}
