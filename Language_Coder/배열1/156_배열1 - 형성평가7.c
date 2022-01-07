#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100] = { 0, };

int main(void) {
	int max_val = -1;
	int min_val = 1000;
	for (int i = 0; i < 100; ++i) {
		int val;
		scanf("%d", &val);
		if (val == 999)
			break;
		else {
			if (max_val < val)
				max_val = val;
			if (min_val > val)
				min_val = val;
		}
		arr[i] = val;
	}

	printf("max : %d\n",max_val);
	printf("min : %d\n",min_val);
	return 0;
}