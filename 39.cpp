#include <iostream>

using namespace std;

int main() {
	int result = 0;
	int max = 0;

	for (int p = 1000; p > 12; p--) {
		int a = (p + 1)/ 2 - 1;
		int b = p / 3;
		int count = 0;
		
		for (int i = a; i > b; i--) {
			int c = (p - i) / 2;
			
			for (int j = i - 1; j > c; j--) {
				int k = p - i - j;
				
				if (k * k + j * j == i * i) {
					count++;
				}
			}
		}
		if (count > max) {
			max = count;
			result = p;
		}
	}
	cout << result << endl;
	return 0;
}
