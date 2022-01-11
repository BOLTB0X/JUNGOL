#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr1[2][3];
	int arr2[2][3];

	printf("first array\n");
	for (int j = 0; j < 2; ++j) {
		for (int k = 0; k < 3; ++k)
			scanf("%d", &arr1[j][k]);
	}

	printf("second array\n");
	for (int j = 0; j < 2; ++j) {
		for (int k = 0; k < 3; ++k)
			scanf("%d", &arr2[j][k]);
	}

	for (int j = 0; j < 2; ++j) {
		for (int k = 0; k < 3; ++k) {
			printf("%d ", arr1[j][k] * arr2[j][k]);
		}
		printf("\n");
	}

	return;
}