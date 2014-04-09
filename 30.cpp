#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int sz[10];
	int result = 0;
	
	sz[0] = 0;
	sz[1] = 1;
	for (int i = 2; i <= 9; i++) {
		sz[i] = pow(i, 5.0);
	}

	int max = sz[9] * 6;
	for (int i = 10; i < max; i++) {
		int num = i;
		int sum = 0;

		while (num) {
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
