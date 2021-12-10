#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	float yd = 91.44;
	float in = 2.54;

	float a = 2.1;
	float b = 10.5;

	printf("%4.1fyd = %5.1fcm\n", a, (float)a * yd);
	printf("%4.1fin = %5.1fcm\n", b, (float)b * in);

	return 0;
}