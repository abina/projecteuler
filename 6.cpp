#include <iostream>

using namespace std;

int main() {
	int ssum = 0;

	for (int i = 0; i < 101; i++) {
		ssum += i * i;
	}
	
	int sum = (100 + 1) * 50;
	int result =  sum * sum - ssum;

	cout << result << endl;
	
	return 0;
}
