#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double arr[6];

int main(void) {
	double tot = 0;
	for (int i = 0; i < 6; ++i) {
		scanf("%lf", &arr[i]);
		tot += arr[i];
	}

	printf("%.1lf", (double)tot / 6);
	return 0;
}