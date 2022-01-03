#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int per[101];

void dice(int level) {
	if (level > n) {
		for (int i = 1; i <= n; ++i) 
			printf("%d ", per[i]);
		printf("\n");
		return;
	}
	
	for (int i = per[level - 1]; i <= 6; ++i) {
		per[level] = i;
		dice(level + 1);
	}

	return;
}

void solution(void) {
	scanf("%d", &n);

	per[0] = 1;

	dice(1);
	return;
}

int main(void) {
	solution();

	return 0;
}
