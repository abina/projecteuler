#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(unsigned long num) {
    if (num == 2) {
        return true;
    }
    if ((num & 1) == 0) {
        return false;
    }
    for (int i = 3; i < sqrt(num) + 1; i += 2) {
        if (num % i == 0) {
    	    return false;
	    }
    }
    return true;
}

int main() {
	int index = 1;

	for (int i = 3; ; i += 2) {
		if (IsPrime(i)) {
			index++;
		}
		if (index == 10001) {
			cout << i << endl;
			break;
		}
	}	
	return 0;
}
