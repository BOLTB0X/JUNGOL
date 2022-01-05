#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int n;
	scanf("%d", &n);
	
	int num = 1, tot = 0, cnt = 0;
	while (1) {
		tot += num;
		num += 2;
		cnt++;
		if (tot >= n)
			break;
	}

	printf("%d %d\n", cnt, tot);
	return;
}

int main(void) {
	solution();
	return 0;
}