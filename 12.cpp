#include <iostream>
#include <cmath>

using namespace std;

int NumOfDivisors(long int num) {
	int sum = 0;
	double s = sqrt(num);
	int i = 1;

	for (; i < s; i++) {
		if (num % i == 0) {
			sum += 2;
		}
	}
	if ((double)i == s) {
		sum++;
	}
	return sum;
}

int main() {
	int sum = 0;
	
	for (int i = 1; ; i++) {
		sum += i;
		if (NumOfDivisors(sum) > 500) {
			cout << sum << endl;
			break;
		}
	}
	return 0;
}
