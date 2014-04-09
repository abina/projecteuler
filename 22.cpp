#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char szName[5163][12];

void getName(char* buff) {
	FILE *fp = fopen("names.txt", "r");
	
	if (fp == NULL) {
		return;
	}
	if (fgets(buff, 47 * 1024, fp) != 0) {
		buff[strlen(buff)-1] = '\0';
		
		char* tmp = strtok(buff, ",");
		int index = 0;
		
		while (tmp != NULL && index < 5163) {
			strncpy(szName[index], ++tmp, strlen(tmp) - 2);
			index++;
			tmp = strtok(NULL, ",");
		}
	}
}

void QuickSort(int l, int h) {
	if (l < h) {
		char tmp[12];
		int i = l;
		int j = h;

		strncpy(tmp, szName[l], strlen(szName[l]) + 1);
		while (i < j) {
			while (j > i && strcmp(szName[j], tmp) > 0) {
				j--;
			}
			if (j > i) {
				strncpy(szName[i], szName[j], strlen(szName[j]) + 1);
			}
			while (i < j && strcmp(szName[i], tmp) < 0) {
				i++;
			}
			if (i < j) {
				strncpy(szName[j], szName[i], strlen(szName[i]) + 1);
			}
		}
		strncpy(szName[i], tmp, strlen(tmp) + 1);
		QuickSort(l, i - 1);
		QuickSort(i + 1, h);
	}
}

int main() {
	char* buff = new char[47 * 1024];
	long int result = 0;
	
	getName(buff);
	free(buff);
	buff = NULL;
	QuickSort(0, 5162);

	for (int i = 0; i < 5163; i++) {
		int score = 0;
		int j = 0;

		while (szName[i][j] != '\0') {
			score += szName[i][j] - 'A';
			j++;
		}
		score += j;
		score *= (i + 1);
		result += score;
	}
	cout << result << endl;
	return 0;
}
