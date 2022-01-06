#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void solution(void) {
	int n, result = -1, tot = 0;

	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);

		if (tot < 0) 
			tot = arr[i];
		
		else {
			tot += arr[i];
			if (tot >= result)
				result = tot;
		}
	}
	if (tot >= result)
		result = tot;

	printf("%d", result);
	free(arr);
	return;
}

int main(void) {
	solution();

	return 0;
}
