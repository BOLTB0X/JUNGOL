#define _CRT_SECURE_NO_WARNINIGS
#include <stdio.h>

int main(void) {
	int e_cnt = 0;
	int o_cnt = 0;
	for (int i = 0; i < 10; ++i) {
		int val;
		scanf("%d", &val);
		if (val % 2 == 0)
			e_cnt++;
		else
			o_cnt++;
	}

	printf("even : %d\n", e_cnt);
	printf("odd : %d\n", o_cnt);

	return 0;
}