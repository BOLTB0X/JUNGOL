#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char arr[6] = { 'J', 'U', 'N', 'G', 'O', 'L' };

int main(void) {
	char tmp;
	scanf(" %c", &tmp);

	for (int i = 0; i < 6; ++i) {
		if (arr[i] == tmp) {
			printf("%d", i);
			return 0;
		}
	}

	printf("none\n");
	return 0;
}