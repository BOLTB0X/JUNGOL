#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num, tot = 0, cnt = 0;
	
	while (1) {
		scanf("%d", &num);
		cnt++;
		if (num < 100)
			tot += num;
		else {
			tot += num;

			printf("%d\n", tot);
			printf("%.1lf\n", (double)tot / cnt);
			break;
		}
	}

	return 0;
}