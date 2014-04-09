#include <iostream>

using namespace std;

int main() {
	int result = 0;
	int max = 0;
	
	for (int i = 999999; i > 99999; i--) {
		int len = 0;
		unsigned int num = i;
		
		while (num != 1) {
			len++;
			if ((num & 1) == 0) {
				num = num >> 1;
			}
			else {
				num = num * 3 + 1;
			}
		}
		if (len > max) {
			max = len;
			result = i;
		}
	}

	cout << result << endl;
	
	return 0;
}
