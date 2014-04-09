#include <iostream>

using namespace std;

int main() {
	int sz[8] = {1, 2, 5, 10, 20, 50, 100, 200};
	int table[201];
	int result = 0;
	
	memset(table, 0, sizeof(table));
	table[0] = 1;
	
	for (int i = 0; i < 8; i++) {
		for (int j = sz[i]; j <= 200; j++) {
			table[j] += table[j-sz[i]];
			cout << j << " " << table[j] << endl;
		}		
	}
	return 0;
}
