#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	while (1) {
		printf("number? ");
		int num;
		scanf("%d", &num);

		if (num > 0)
			printf("positive integer\n");
		else if (num < 0)
			printf("negative number\n");
		else
			break;
	}

	return 0;
}