#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool sz[521];
char szWord[1786][20];

void GetTriangle() {
	for (int i = 1; i < 32; i++) {
		int tmp  = i * (i + 1) / 2;
		sz[tmp] = true;
	}
}


void getName(char* buff) {
	FILE *fp = fopen("words.txt", "r");

	if (fp == NULL) {
		return;
	}
	if (fgets(buff, 17 * 1024, fp) != 0) {
		buff[strlen(buff)-1] = '\0';

		char* tmp = strtok(buff, ",");
		int index = 0;

		while (tmp != NULL && index < 5000) {
			strncpy(szWord[index], ++tmp, strlen(tmp) - 2);
			index++;
			tmp = strtok(NULL, ",");
		}
	}
}

int main() {
	int result = 0;
	char* str = new char[17 * 1024];
	
	getName(str);
	free(str);
	GetTriangle();

	for (int i = 0; i < 1786; i++) {
		int tmp = strlen(szWord[i]);
		int sum = 0;

		for (int j = 0; j < tmp; j++) {
			sum += szWord[i][j] - 'A' + 1;
		}
		if (sz[sum]) {
			result++;
		}
	}
	cout << result << endl;
	return 0;
}
