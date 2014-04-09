#include <iostream>

using namespace std;

int main() {
	int c = 499;
	int a = 0;
	int b = 0;

	while (c > 333) {
		bool flag = false;
		int tmpc = c * c;
		
		a = (1000 - c) / 2;
		if ((c & 1) == 0) {
			b = a;
		}
		else {
			b = a + 1;
		}
		while (b < c) {
			int tmpab = a * a + b * b;

			if (tmpab == tmpc) {
				flag = true;
				break;
			}
			if (tmpab < tmpc) {
				b++;
				a--;
				continue;
			}
			if (tmpab > tmpc) {
				break;
			}
		}
		if (flag) {
			break;
		}
		c--;
	}

	int result = a * b * c;
	cout << result << endl;
	
	return 0;
}
