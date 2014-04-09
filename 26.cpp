#include <iostream>

using namespace std;

int GetLen(int n) {
	bool bHas[1000];
	int szCount[1000];
	int num = 1;
	int count = 0;
	
	memset(bHas, 0, sizeof(bHas));
	memset(szCount, 0, sizeof(szCount));
	do {
		while (num < n) {
			count++;
			num *= 10;
		}
		num = num % n;
		if (bHas[num]) {
			return count - szCount[num];
		}
		bHas[num] = true;
		szCount[num] = count;		
	} while (num);

	return 0;
}

int main() {
	int result = 0;
	int max = 0;

	for (int i = 7; i < 1000; i++) {
		int tmp = GetLen(i);

		if (tmp > max) {
			max = tmp;
			result = i;
		}
	}
	cout << result << endl;
	return 0;
}
