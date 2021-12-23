#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[5];
	int* ptr1;

	for (int i = 0; i < 5; ++i)
		scanf("%d", &arr[i]);
	ptr1 = arr;

	for (int i = 0; i < 5; ++i) {
		if (i%2 == 0)
			printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}