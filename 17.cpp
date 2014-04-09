#include <iostream>

using namespace std;

int sz19[9] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
int szTeen[10] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int szTen[8] = {6, 6, 5, 5, 5, 7, 6, 6};

int main() {
	int result = 0;
	int tmp19 = 0;
	int tmpteen = 0;
	int tmpten = 0;
	int tmph = 0;

	for (int i = 0; i < 9; i++) {
		tmp19 += sz19[i];
	}
	for (int i = 0; i < 10; i++) {
		tmpteen += szTeen[i];
	}
	for (int i = 0; i < 8; i++) {
		tmpten += szTen[i] * 10;
		tmpten += tmp19;
	}
	tmpten = tmp19 + tmpteen + tmpten;
	for (int i = 0; i < 9; i++) {
		tmph += (sz19[i] + 10) * 99 + tmpten + sz19[i] + 7;
	}
	result = 11 + tmph + tmpten;
	cout << result << endl;
	return 0;
}
