#include <iostream>
#include <cmath>

using namespace std;

bool sz[500000];

void GetPrime() {
	int szPrime[78500];
	int index = 0;
	
	szPrime[0] = 2;
	memset(szPrime, 0, sizeof(szPrime));	
	for (int i = 3; i < 1000000; i += 2) {
		int tmp = (int)sqrt(i);
		bool flag = true;
		for (int j = 0; j < index && szPrime[j] <= tmp; j++) {
			if (i % szPrime[j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			sz[i/2] = true;
			szPrime[index++] = i;
		}
	}
}

int main() {
	int result = 1;

	GetPrime();	
	for (int i = 3; i < 1000000; i += 2) {
		if (sz[i/2]) {
			int digits = 0;
			int num = i;
			bool flag = false;
			
			while (num != 0) {
				if (num % 10 % 2 == 0) {
					flag = true;
					break;
				}
				digits++;
				num /= 10;
			}
			if (flag) {
				continue;
			}
			int mul = (int)pow(10.0, (digits - 1));
			num = i;
			do {
				num = (num % 10) * mul + num / 10;
				if (!sz[num/2]) {
					break;
				}
			}while (num != i);
			if (num == i) {
				result++;
			}
		}
	}
	cout << result << endl;
	return 0;
}
