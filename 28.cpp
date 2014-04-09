#include <iostream>

using namespace std;

int main() {
	int result = 1;

	for (int i = 3; i <= 1001; i += 2) {
		result += i * i;
		result += (i - 1) * (i - 2) + 1;
		result += (i - 1) * (i - 1) + 1;
		result += i * (i - 1) + 1;
	}
	cout << result << endl;
	return 0;
}
