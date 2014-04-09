#include <iostream>

using namespace std;

int main() {
	int result = 0;
	bool flag[10];

	for (int i = 9999; i > 5000; i--) {
		int num = i * 100000 + i * 2;
		bool bContinue = false;
		
		memset(flag, 0, sizeof(flag));
		while (num) {
			int tmp = num % 10;
			if (tmp == 0 || flag[tmp]) {
				bContinue = true;
				break;
			}
			flag[tmp] = true;
			num /= 10;
		}
		if (bContinue) {
			continue;
		}
		result = i;
		break;
	}
	cout << result << endl;
	return 0;
}
