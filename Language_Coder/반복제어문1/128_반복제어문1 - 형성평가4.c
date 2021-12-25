#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num,cnt = 0;

	while (1) {
		scanf("%d", &num);
		if (num == 0)
			break;

		else if (num % 5 != 0 && num % 3 != 0)
			cnt++;
	}
	printf("%d\n", cnt);


	return 0;
}