#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int* ptr;
	ptr = &n;
	
	scanf("%d", &n);
	

	printf("%p %d\n", ptr, *ptr);

	return 0;
}