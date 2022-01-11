#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[4][2];

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
	int tot = 0;
	//°¡·Î Æò±Õ
	for (int i = 0; i < 4; ++i) {
		printf("%d ", (int)(arr[i][0] + arr[i][1])/2);
	}
	printf("\n");


	//»õ·Î Æò±Õ
	for (int i = 0; i < 2; ++i) {
		printf("%d ", (int)(arr[0][i] + arr[1][i] + +arr[2][i] +arr[3][i]) / 4);
	}
	printf("\n");
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j)
			tot += arr[i][j];
	}
	printf("%d\n", tot / 8);

	return;
}