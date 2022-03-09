#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[11] = { 0, };

	int val;
	for (int i = 0; i < 100; ++i) {
		scanf("%d", &val);
		if (val == 0)
			break;
		
		arr[val/10]++;
	}

	for (int i = 10; i >= 0; --i) {
		if (arr[i] == 0)
			continue;
		
		printf("%d : %d person\n", i * 10, arr[i]);
	}

	return;
}
