#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, m;
	int tot = 0;
	int cnt = 0;

	scanf("%d %d", &n, &m);
	if (n < m) {
		for (int i = n; i <= m; ++i) {
			if (i % 3 == 0 || i % 5 == 0) {
				tot += i;
				cnt++;
			}
		}
	}
	else {
		for (int i = m; i <= n; ++i) {
			if (i % 3 == 0 || i % 5 == 0) {
				tot += i;
				cnt++;
			}
		}
	}
	double avg = (double)tot / cnt;
	printf("sum : %d\n",tot);
	printf("avg : %.1lf\n", avg);

	return 0;
}