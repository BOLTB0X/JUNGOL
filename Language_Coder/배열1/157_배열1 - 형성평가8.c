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
		if (val % 5 == 0) {
			tot += val;
			cnt++;
		}
		arr[i] = val;
	}

	printf("Multiples of 5 : %d\n", cnt);
	printf("sum : %d\n", tot);
	printf("avg : %.1lf\n",(double)tot/cnt);
	return 0;
}