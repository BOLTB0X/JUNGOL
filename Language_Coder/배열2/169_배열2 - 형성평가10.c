#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char arr[3][5];
	
	char alp;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf(" %c", &alp);
			arr[i][j] = alp + 32;
		}
	}
	
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 5; ++j) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}

	return;
}