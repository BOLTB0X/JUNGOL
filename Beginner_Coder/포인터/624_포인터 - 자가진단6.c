#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void solution(void) {
	int n;
	double tot = 0;
	scanf("%d", &n);
	double* arr = malloc(sizeof(double) * n);

	for (int i = 0; i < n; ++i) {
		scanf("%lf", &arr[i]);
		tot += arr[i];
	}
	
	for (int i = 0; i < n; ++i)
		printf("%.2lf ", arr[i]);
	printf("\n");
	
	printf("hap : %.2lf\n", tot);
	printf("avg : %.2lf\n", (double)tot / n);

	return;
}

int main(void) {
	solution();
	return 0;
}