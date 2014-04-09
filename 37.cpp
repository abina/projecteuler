#include <iostream>
#include <cmath>

using namespace std;

int szPrime[5000];
int szTruncatable[11];
int szLen[10];
int gCount;

bool IsPrime(int num) {
	if (num == 2) {
		return true;
	}
	if ((num & 1) == 0) {
		return false;
	}

	int tmp = (int)sqrt(num);

	for (int i = 3; i <= tmp; i += 2) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

bool IsR2L(int num) {
	do {
		num /= 10;
		if (!IsPrime(num)) {
			return false;
		}
	}while (num > 10);
	return true;
}
void BuildPrime(int no) {
	int nIndex = szLen[no-1];

	for (int i = 1; i < 10; i++) {
		for (int j = szLen[no-2]; j < szLen[no-1]; j++) {
			int num = i * (int)pow(10.0, no - 1) + szPrime[j];

			if (IsPrime(num)) {
				szPrime[nIndex++] = num;
				if (i == 2 || i == 3 || i == 7 || i == 5) {
					if (IsR2L(num)) {
						szTruncatable[gCount++] = num;
						if (gCount >= 11) {
							return;
						}
					}
				}
			}
		}
	}
	szLen[no] = nIndex;
}

int main() {
	int result = 0;

	szPrime[0] = 2;
	szPrime[1] = 3;
	szPrime[2] = 5;
	szPrime[3] = 7;
	szLen[0] = 0;
	szLen[1] = 4;

	for (int i = 2; gCount < 11; i++) {
		BuildPrime(i);
	}
	for (int i = 0; i < gCount; i++) {
		result += szTruncatable[i];
	}

	cout << result << endl;
	return 0;
}
