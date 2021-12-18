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
	int key = start, i = start + 1, j = end; //i�� ���� j�� ������, �ǹ� ���� ���� �������� ����
	while (i <= j) { //�������� ������ �ݺ�
		while (i <= end && arr[i] <= arr[key]) 
			i++; //key���� ū ���� i�� ����.
		while (j > start && arr[j] >= arr[key]) 
			j--; //key���� ���� ���� j�� ��⵵��
		if (i > j) 
			swap(&arr[key], &arr[j]);
		else 
			swap(&arr[i], &arr[j]);
	}
	// ������ �� �κ��� ��������� ȣ��
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