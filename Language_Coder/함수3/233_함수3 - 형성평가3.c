#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int per[10];
int per_idx = 0;

void dice(int level, int sum) {
	for (int i = 1; i <= 6; ++i) {
		per[per_idx] = i;

		if (per_idx == level - 1) {
			int tot = 0;
			for (int j = 0; j <n; ++j)
				tot += per[j];

			if (tot == sum) {
				for (int k = 0; k <n; ++k)
					printf("%d ", per[k]);
				printf("\n");
				return;
			}
		}

		else {
			per_idx++;
			dice(level, sum);
			per_idx--;
		}
	}

	return;
}

void solution(void) {
	scanf("%d %d", &n, &m);

	dice(n, m);
	return;
}

int main(void) {
	solution();

	return 0;
}