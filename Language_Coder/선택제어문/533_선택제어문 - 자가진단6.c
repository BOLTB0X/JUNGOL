#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char c;
	int old;

	scanf("%c %d", &c, &old);

	if (c == 'F') {
		if (old >= 18)
			printf("WOMAN\n");
		else
			printf("GIRL\n");
	}
	else if (c == 'M') {
		if (old >= 18)
			printf("MAN\n");
		else
			printf("BOY\n");
	}

	return 0;
}