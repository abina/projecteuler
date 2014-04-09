#include <iostream>

using namespace std;

int sza[112];
int szb[112];

int main() {
	int result = 2;
	bool bA = true;
	int carry = 0;
	int max = 999999999;
	
	sza[0] = 1;
	szb[0] = 1;
	while (sza[111] == 0 && szb[111] == 0) {
		result++;
		if (bA) {
			for (int i = 0; i < 112; i++) {
				sza[i] = sza[i] + szb[i] + carry;
				if (sza[i] > max) {
					sza[i] -= max + 1;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
			bA = false;
		}
		else {
			for (int i = 0; i < 112; i++) {
				szb[i] = sza[i] + szb[i] + carry;
				if (szb[i] > max) {
					szb[i] -= max + 1;
					carry = 1;
				}
				else {
					carry = 0;
				}
			}
			bA = true;
		}
	}
	cout << result << endl;
	return 0;
}
