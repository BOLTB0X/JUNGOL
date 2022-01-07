#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100] = { 0, };

int main(void) {
	int cnt = 0;
	int tot = 0;

	int val;
	for (int i = 0; i < 100; ++i) {
		scanf("%d", &val);
		if (val == 0)
			break;
		arr[i] = val;
		cnt++;
	}

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i) {
		if (arr[i] % 2 != 0)
			printf("%d ", arr[i] * 2);
		else
			printf("%d ", arr[i] / 2);
	}
	return 0;
}