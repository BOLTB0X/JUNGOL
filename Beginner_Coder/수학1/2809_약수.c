#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arr[10000];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void quick_Sort(int start, int end) {
	if (start >= end) 
		return;
	int key = start, i = start + 1, j = end; //i는 왼쪽 j는 오른쪽, 피벗 값을 가장 왼쪽으로 가정
	while (i <= j) { //엇갈리기 전까지 반복
		while (i <= end && arr[i] <= arr[key]) 
			i++; //key보다 큰 값이 i에 담긴다.
		while (j > start && arr[j] >= arr[key]) 
			j--; //key보다 작은 값이 j에 담기도록
		if (i > j) 
			swap(&arr[key], &arr[j]);
		else 
			swap(&arr[i], &arr[j]);
	}
	// 엇갈릴 때 부분적 재귀적으로 호출
	quick_Sort(start, j - 1);
	quick_Sort(j + 1, end);
}

void solution(void) {
	int n, idx = 0;
	scanf("%d", &n);

	for (int i = 1; i <= (int)sqrt(n); ++i) {
		if (n % i == 0) {
			arr[idx++] = i;
			if (n / i != i)
				arr[idx++] = n / i;
		}
	}

	quick_Sort(0, idx - 1);

	for (int i = 0; i < idx; ++i) 
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void) {
	solution();
	return 0;
}