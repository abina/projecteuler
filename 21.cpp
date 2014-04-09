#include <iostream>
#include <cmath>

using namespace std;

int sz[10001];

int getD(int num) {
	double tmp = sqrt(num);
	int sum = 1;
	
	for (int i = 2; i < tmp; i++) {
		if (num % i == 0) {
			sum += i;
			sum += num / i;
		}
	}
	return sum;
}

int main() {
	int result = 0;
	
	for (int i = 2; i < 10001; i++) {
		sz[i] = getD(i);
	}
	for (int i = 2; i < 10001; i++) {
		if (sz[i] != 1 && sz[i] != i && sz[i] < 10001 && i == sz[sz[i]]) {
			result += i + sz[i];
		}
	}
	result /= 2;
	cout << result << endl;
	return 0;
}
