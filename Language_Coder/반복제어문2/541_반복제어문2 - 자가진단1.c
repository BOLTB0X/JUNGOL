#include <stdio.h>

int main(void) {
	char ch;
	scanf("%c", &ch);

	for (int i = 0; i < 20; ++i)
		printf("%c", ch);

	return 0;
}