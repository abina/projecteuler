#include <iostream>

using namespace std;

int main() {
	long int result = 1;
	int sz[21];
	
	for (int i = 1; i < 21; i++) {
		sz[i] = i;
	}
	
	int begin = 40; 
	int end =  35;

	while (end >= 20) {
		for (int i = begin; i > end; i--) {
			result *= i;
		}
		for (int i = 1; i < 21; i++) {
			if (sz[i] != 0 && result % i == 0) {
				result /= i;
				sz[i] = 0;
			}
		}
		begin -= 5;
		end -= 5;
	}
	for (int i = 2; i < 21; i++) {
		if (sz[i] != 0) {
			result /= i;
		}
	}

	cout << result << endl;
	return 0;
}
