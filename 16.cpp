#include <iostream>

using namespace std;

int main() {
	int sz[40];

	sz[0] = 1;
	for (int i = 1; i < 40; i++) {
		sz[i] = 0;
	}

	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 40; j++) {
			sz[j] *= 2;
		}
		for (int j = 0; j < 39; j++) {
			if (sz[j] > 999999999) {
				sz[j+1]++;
				sz[j] -= 1000000000;
			} 
		}
	}
	
	int result = 0;

	for (int i = 0; i < 40; i++) {
		while (sz[i]) {
			result += sz[i] % 10;
			sz[i] /= 10;
		}
	}

	cout << result << endl;
	return 0;
}
