#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int arr[10];
	int* n = arr;
	for (int i = 0; i < 10; ++i)
		scanf("%d", &n[i]);
	
	int even_cnt = 0;
	for (int i = 0; i < 10; ++i)
		if (n[i] % 2 == 0)
			even_cnt++;

	printf("odd : %d\n", 10 - even_cnt);
	printf("even : %d\n", even_cnt);
			
	return;
}

int main(void) {
	solution();
	return 0;
}