#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MS 500001 //최대 길이

typedef struct {
	int idx, height;
} Transter;

Transter stack[MS];
int top = -1;

void push(Transter data) {
	stack[++top] = data;
	return;
}

void pop(void) {
	top--;
	return;
}

int* solution(int n, int* arr) {
	int* answer = malloc(sizeof(int) * (n + 1));

	//문제조건에 따라
	for (int i = n - 1; i >= 0; --i) {
		//스택이 비었다면
		if (top == -1) {
			Transter t = { i, arr[i] };
			push(t);
		}

		else {
			//스택이 비어있지 않고 현재 송신기가 스택원소를 받을 수 있다면
			while (top != -1 && stack[top].height < arr[i]) {
				answer[stack[top].idx] = i + 1;
				pop();
			}

			//현재 송신기를 다시 푸쉬
			Transter t = { i, arr[i] };
			push(t);
		}
	}

	while (top != -1) {
		answer[stack[top].idx] = 0;
		pop();
	}

	return answer;
}

int main(void) {
	int n;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	int* ret = solution(n, arr);
	//출력
	for (int i = 0; i < n; ++i)
		printf("%d ", ret[i]);
	
	free(arr);
	return 0;
}