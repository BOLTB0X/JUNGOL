#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
int per[10];
int per_idx = 0;

void dice(int level, int target) {
	for (int i = 1; i <= 6; ++i) {
		per[per_idx] = i;

		if (per_idx == level) {
			int tot = 0;
			for (int i = 0; i < level; ++i)
				tot += per[i]; 
			
			if (tot == target) {
				for (int j = 0; j < level; ++j)
					printf("%d ", per[j]);
				printf("\n");
			}
			return;
		}
		else {
			per_idx++;
			dice(level, target);
			per_idx--;
		}
	}

	return;
}

int main(void) {
	scanf("%d %d", &n, &m);
	dice(n, m);

	return 0;
}