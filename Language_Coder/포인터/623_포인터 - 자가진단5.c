#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double arr[5];
	double* ptr1;

	for (int i = 0; i < 5; ++i)
		scanf("%lf", &arr[i]);
	ptr1 = arr;

	for (int i = 0; i < 5; ++i) 
		printf("%.1lf ", arr[i]);
	printf("\n");

	return 0;
}