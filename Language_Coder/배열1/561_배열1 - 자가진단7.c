#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int val, min_val = 10001, max_val = -1;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &val);

		if (val >= 100) {
			if (min_val > val)
				min_val = val;
		}
		else {
			if (max_val < val)
				max_val = val;
		}
	}

	if (max_val == -1)
		max_val = 100;
	else if (min_val == 10001)
		min_val = 100;
	printf("%d %d", max_val, min_val);
	return 0;
}