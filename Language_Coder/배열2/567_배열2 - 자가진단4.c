#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[15] = { 5,8,10,6,4,11 ,20,1,13, 2,7,9,14,22,3 };
	
	for (int i = 0; i < 15; ++i) {
		printf("%2d   ", arr[i]);
		if (i == 4 || i == 9 || i == 14)
			printf("\n");
	}

	return;
}