#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main(void) {
	int a = 0;
	time_t now;
	struct tm tt;
	time(&now);
	tt = *localtime(&now);
	a = tt.tm_year;
	a += tt.tm_mon;
	a += tt.tm_mday;
	// 0 121 132
	printf("%d %d %d\n", a);

	return 0;
}