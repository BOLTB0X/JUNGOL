#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[500001];
int targets[500001];

int binary_Search(int target,int left, int right) {
	int mid = (left + right) / 2;

	if (left > right)
		return -1;
	if (arr[mid] == target)
		return mid;
	else if (target > arr[mid])
		binary_Search(target, mid + 1, right);
	else
		binary_Search(target, left, mid - 1);
}

void solution(void) {
	int n, m;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	
	scanf("%d", &m);

	for (int i = 0; i < m; ++i) {
		int val;
		scanf("%d", &val);
		int ret = binary_Search(val, 0, n - 1);
		printf("%d ", ret);
	}


	return;
}

int main(void) {
	solution();
	return 0;
}