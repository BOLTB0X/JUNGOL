#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num ;
	scanf("%d", &num);
	int tot = 0;

	while (num != 0)
		tot += num--;

	printf("%d\n", tot);
	return 0;
}