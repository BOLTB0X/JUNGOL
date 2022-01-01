#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char asc;

	while (1) {
		scanf(" %c", &asc);

		if (asc >= '0' && asc <= '9')
			printf("%d\n", asc);
		else if (asc >= 'a' && asc <= 'z')
			printf("%c\n", asc);
		else if (asc >= 'A' && asc <= 'Z')
			printf("%c\n", asc);
		else
			break;
	}

	return 0;
}