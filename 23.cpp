#include <iostream>
#include <cmath>

using namespace std;

bool bAbundant[28124];

bool IsAbundant(int num) {
	int sum = 1;
	double tmp = sqrt(num);

	for (int i = 2; i < tmp; i++) {
		if (num % i == 0) {
			sum += i;
			sum += num / i;
		}
	}
	if (tmp == (int)tmp) {
		sum += (int)tmp;
	}
	if (sum > num) {
		return true;
	}
	return false;	
}

int main() {
	int result = 0;
	
	for (int i = 12; i < 28124; i++) {
		bAbundant[i] = IsAbundant(i);
	}
	for (int i = 1; i < 28124; i++) {
		bool flag = true;
		int tmp = i / 2;

		for (int j = 12; j <= tmp; j++) {
			if (bAbundant[j] && bAbundant[i-j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			result += i;
		}
	}
	cout << result << endl;
	return 0;
}
