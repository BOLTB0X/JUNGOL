#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int val, min_val = 1001;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &val);

		if (min_val > val)
			min_val = val;
	}

	printf("%d", min_val);
	return 0;
}