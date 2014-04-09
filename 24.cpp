#include <iostream>

using namespace std;

int szNum[10];
bool bUse[10];

int main() {
	unsigned int result = 0;
	int digit = 0;
	int num = 1000000;
	int index = 9;

	szNum[1] = 1;
	for (int i = 2; i < 10; i++) {
		szNum[i]= szNum[i-1] * i;
	}
	while (num > 0 && index > 0) {
		digit = num / szNum[index];
		num = num % szNum[index];
		if (num == 0) {
			num = digit;
			digit--;
		}
		for (int i = 0; i <= digit; i++) {
			if (bUse[i]) {
				digit++;
			}
		}
		bUse[digit] = true;
		result = result * 10 + digit;
		index--;
	}
	for (int i = 0; i < 10; i++) {
		if (bUse[i] == false) {
			result = result * 10 + i;
			break;
		}
	}
	cout << result << endl;
	return 0;
}
