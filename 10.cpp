#include <iostream>
#include <cmath>

using namespace std;

int a[1000000] = {2, 0};

int main() {
	unsigned long sum = 2;
	int index = 1;

	for (int i = 3; i < 2000000; i += 2) {
		bool flag = true;
		int tmp = sqrt(i) + 1;
		
		for (int k = 1; a[k] < tmp && a[k] != 0; k++) {
			if (i % a[k] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			a[index++] = i;
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}
