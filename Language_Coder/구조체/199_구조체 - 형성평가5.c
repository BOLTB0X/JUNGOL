#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct INFO {
	char name[20];
	int a;
	int b;
	int c;
	int tot;
} INFO;

void sort(INFO* arr, int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[i].tot < arr[j].tot) {
				INFO tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	INFO* arr = malloc(sizeof(INFO) * n);
	for (int i = 0; i < n; ++i) {
		scanf("%s %d %d %d", arr[i].name, &arr[i].a, &arr[i].b, &arr[i].c);
		arr[i].tot = arr[i].a + arr[i].b + arr[i].c;
	}

	sort(arr, n);

	for (int i = 0; i < n; ++i)
		printf("%s %d %d %d %d\n", arr[i].name, arr[i].a, arr[i].b, arr[i].c, arr[i].tot);
	return;
}

int main(void) {
	solution();
	return 0;
}