#include <iostream>

using namespace std;

int main() {
	int sz[24];

	sz[0] = 1;
	for (int i = 1; i < 24; i++) {
		sz[i] = 0;
	}

	for (int i = 1; i < 100; i++) {
		for (int j = 0; j < 24; j++) {
			sz[j] *= i;
		}
		for (int j = 0; j < 23; j++) {
			if (sz[j] > 9999999) {
				sz[j+1] += sz[j] / 10000000;
				sz[j] = sz[j] % 10000000;
			} 
		}
	}
	
	int result = 0;

	for (int i = 0; i < 24; i++) {
		while (sz[i]) {
			result += sz[i] % 10;
			sz[i] /= 10;
		}
	}

	cout << result << endl;
	return 0;
}
