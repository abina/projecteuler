#include <iostream>

using namespace std;

int main() {
	int result = 0;

	for (int i = 1; i < 1000000; i += 2) {
		char sz[20];
		int len = 0;
		int num = i;
		bool flag = true;
		
		if (i > 100) {
			memset(sz, 0, sizeof(sz));
			while (num) {
				sz[len++] = num % 10;
				num /= 10;
			}
			for (int j = 0; j < len / 2; j++) {
				if (sz[j] != sz[len-1-j]) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				continue;
			}			
		}
		else if (i > 10 && i < 100 && i % 11 != 0) {
			continue;
		}
		
		memset(sz, 0, sizeof(sz));
		num = i;
		len = 0;
		while (num) {
			sz[len++] = num & 1;
			num = num >> 1;
		}
		for (int j = 0; j < len / 2; j++) {
			if (sz[j] != sz[len-1-j]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			continue;
		}
		result += i;
	}
	cout << result << endl;
	return 0;
}
