#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_string(void) {
	printf("~!@#$^&*()_+|\n");
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		print_string();

	return 0;
}