#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int per[10];

void dice(int level) {
	if (level == n) {
		int tot = 0;
		for (int i = 0; i < n; ++i)
			tot += per[i];

		if (tot == m) {
			for (int i = 0; i < n; ++i)
				printf("%d ", per[i]);
			printf("\n");
		}
		return;
	}

	for (int i = 1; i <= 6; ++i) {
		per[level] = i;
		dice(level + 1);
	}

	return;
}

void solution(void) {
	scanf("%d %d", &n, &m);

	dice(0);
	return;
}

int main(void) {
	solution();

	return 0;
}