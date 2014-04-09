#include <iostream>

using namespace std;

int main() {
	int result = 0;
	int sz[10];

	sz[0] = 1;
	sz[1] = 1;
	for (int i = 2; i < 10; i++) {
		sz[i] = i;
		for (int j = i - 1; j > 0; j--) {
			sz[i] *= j;
		}
	}

	for (int i = 11; i < 2500000; i++) {
		int num = i;
		int sum = 0;

		while (num != 0) {
			sum += sz[num % 10];
			num /= 10;
		}
		if (sum == i) {
			result += i;
		}
	}
	cout << result << endl;
	return 0;
}
