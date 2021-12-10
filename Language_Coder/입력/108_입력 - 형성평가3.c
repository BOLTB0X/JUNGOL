#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a = 50; 
	float b = 100.12;

	printf("%.2f * %d = %.f\n", b, a, (float)a * b);
	return 0;
}