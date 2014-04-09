#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(unsigned long num) {
	if (num == 2) {
		return true;
	}
	if ((num & 1) == 0) {
		return false;
	}
	for (int i = 3; i < sqrt(num) + 1; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	
	unsigned long a = 600851475143;

	for (unsigned long i = (sqrt(a) + 1); i >= 2; i--) {
		if (IsPrime(i)) {
			if ((a % i) == 0) {
				cout << i << endl;
				return 0;
			}
		}
	}
	
	return 0;
}
