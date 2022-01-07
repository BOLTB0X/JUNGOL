#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int days[31] = { 0, };
int flag = 0;

void solution(void) {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k/2; ++i) {
		days[1] = i;
		for (int j = i + 1; j <= k; ++j) {	
			days[2] = j;
			
			for (int l = 3; l <= n; ++l) {
				days[l] = days[l - 1] + days[l - 2];
				
				if (days[l] >= k)
					break;
			}

			if (days[n] == k) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	printf("%d\n", days[1]);
	printf("%d\n", days[2]);

	return;
}

int main(void) {
	solution();
	return 0;
}
