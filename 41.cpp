#include <iostream>

using namespace std;

bool IsPrime(int num) {
	if (num == 2) {
		return true;
	}
	if ((num & 1) == 0) {
		return false;
	}
	for (int i = 3; i * i < num; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

bool IsPandigital(int num, int len) {
	bool sz[9];

	if (len > 9) {
		return false;
	}
	memset(sz, 0, sizeof(sz));
	do {
		int tmp = num % 10;
		
		if (tmp > len || tmp < 1 || sz[tmp-1]) {
			return false;
		}
		sz[tmp-1] = true;
		num /= 10;
	}while(num);
	return true;
}

int main() {
	int result = 0;

	for (int i = 7654321; i > 1234567; i--) {
		if (IsPandigital(i, 7) && IsPrime(i)) {
			result = i;
			break;
		}
	}
	cout << result << endl;
	return 0;
}
