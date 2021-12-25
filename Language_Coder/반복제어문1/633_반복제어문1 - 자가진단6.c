#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num;

	while (1) {
		printf("1. Korea\n");
		printf("2. USA\n");
		printf("3. Japan\n");
		printf("4. China\n");
		
		printf("number? ");
		scanf("%d", &num);
		printf("\n");

		if (num == 1)
			printf("Seoul\n");
		else if (num == 2)
			printf("Washington\n");
		else if (num == 3)
			printf("Tokyo\n");
		else if (num == 4)
			printf("Beijing\n");
		else {
			printf("none\n");
			break;
		}

		printf("\n");
	}


	return 0;
}