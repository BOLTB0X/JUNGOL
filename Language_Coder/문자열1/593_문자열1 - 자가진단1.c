#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	while (1) {
		int alp;
		printf("ASCII code =? ");
		scanf("%d", &alp);
		if (alp >= 33 && alp <= 127)
			printf("%c\n", alp);
		else
			break;
	}
	
}