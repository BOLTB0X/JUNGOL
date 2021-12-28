#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a, b, c;
	int tot;
} INFO;

void print_struct(INFO* arr) {
	for (int i = 0; i < 3; ++i) {
		arr[3].a += arr[i].a;
		arr[3].b += arr[i].b;
		arr[3].c += arr[i].c;
		arr[3].tot += arr[i].a + arr[i].b + arr[i].c;
	}

	for (int i = 0; i < 4; ++i) {
		printf("%d %d %d %d\n", arr[i].a, arr[i].b, arr[i].c, arr[i].tot);
	}

	return;
}

void solution(void) {
	INFO* arr = malloc(sizeof(INFO) * 4);
	for (int i = 0; i < 4; ++i) {
		arr[i].a = 0;
		arr[i].b = 0;
		arr[i].c = 0;
		arr[i].tot = 0;
	}

	for (int i = 0; i < 3; ++i) {
		scanf("%d %d %d", &arr[i].a, &arr[i].b, &arr[i].c);
		arr[i].tot = arr[i].a + arr[i].b + arr[i].c;
	}
	
	print_struct(arr);
	free(arr);
	
	return;
}

int main(void) {
	solution();
	return 0;
}