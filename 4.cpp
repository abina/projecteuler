#include <iostream>
#include <cmath>

using namespace std;

bool IsPalindrome(int num) {
	char szD[6] = {0};
	int h = 0;
	int l = 0;

	while (num != 0) {
		szD[h++] = num % 10;
		num = num / 10;
	}
	h--;
	while (h > l) {
		if (szD[l++] != szD[h--]) {
			return false;
		}
	}
	return true;
}

bool IsDivisible(int num) {
	for (int i = sqrt(num); i <= 999; i++) {
		if (num % i == 0 && (num / i > 99)) {			
			return true;
		}
	}
	return false;
}

int main() {
	for (int i = 998000; i >= 10000; i--) {
		if (IsPalindrome(i)) {
			if (IsDivisible(i)) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
