#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	float a = 80.5, b = 22.34;

	printf("%10.2f%10.2f%10.2f\n", a, b, (float)a + b);
	return 0;
}