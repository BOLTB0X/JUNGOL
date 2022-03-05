#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>

void solution(int* occ, int A, int B, int C) {
	int tmp = A * B * C;

	while (tmp > 0) {
		int rest = tmp % 10;
		occ[rest]++;
		tmp /= 10;
	}

	return;
}

int main(void) {
	int occ[10] = { 0, };
	int num1, num2, num3;
	scanf("%d %d %d", &num1, &num2, &num3);

	solution(occ, num1, num2, num3);

	for (int i = 0; i < 10; ++i) 
		printf("%d\n", occ[i]);
	
	return 0;
}
