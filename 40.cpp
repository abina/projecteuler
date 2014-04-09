#include <iostream>
#include <cmath>

using namespace std;

int sz[7];

void GetNum() {
	int min = 1;
	int max = 1;
	
	for (int i = 1; i < 7; i++) {
		max *= 10;
		sz[i] = i * (max - min) + sz[i-1];
		min = max;
	}
}

int GetDigit(int th) {
	for (int i = 1; i < 7; i++) {
		int b = 0;
		
		if (sz[i] > th) {
			th -= sz[i-1];
			b = (int)pow(10.0, i - 1) + th / i;
			if (th % i == 0) {
				b--;
				return b % 10;
			}
			for (int j = 0; j < i - (th % i); j++) {
				b /= 10;
			}
			return b % 10;
		}
	}
}

int main() {
	int result = 1;
	
	GetNum();
	for (int i = 1; i <= 100000; i *= 10) {
		result *= GetDigit(i);
	}

	cout << result << endl;
	return 0;
}
