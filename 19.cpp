#include <iostream>

using namespace std;

int main() {
	int day = 366;
	int result = 0;

	for (int i = 1901; i <= 2000; i++) {
		for (int j = 1; j <= 12; j++) {
			if (day % 7 == 0) {
				result++;
			}
			switch (j) {
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					day += 31;
					break;
				case 2:
					if (i % 400 == 0) {
						day += 29;
					}
					else if(i % 100 != 0 && i % 4 == 0) {
						day += 29;
					}
					else {
						day += 28;
					}
					break;
				default:
					day += 30;
					break;
			}
		}
	}
	cout << result << endl;
	return 0;
}
