#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	
	int num = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", num);

			num += 2;

			if (num >= 11)
				num = 1;
		}
		printf("\n");
	}

	return 0;
}