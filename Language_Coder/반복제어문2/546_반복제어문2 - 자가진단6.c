#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	double tot = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int val;
		scanf("%d", &val);

		tot += val;
	}

	printf("avg : %.1lf\n", (double)(tot/n));
	
	if ((tot / n) >= 80)
		printf("pass");
	else
		printf("fail");
	return 0;
}