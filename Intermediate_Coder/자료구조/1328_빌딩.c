#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MN 100001

typedef struct {
	int idx, height;
} Node;

Node stack[MN];
int top = -1;
int arr[MN];

void push(Node data) {
	stack[++top] = data;
	return;
}

void pop(void) {
	return top--;
}

int* solution(int n) {
	int* answer = malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n; ++i) {
		//스택이 비어 있다면
		if (top == -1) {
			Node cur = { i, arr[i] };
			push(cur);
		}

		else {
			//해당 빌딩이 스택안에 빌딩보다 크면
			while (top != -1 && stack[top].height < arr[i]) {
				answer[stack[top].idx] = i + 1;
				pop();
			}

			//현재 빌딩 다시 스택으로
			Node cur = { i, arr[i] };
			push(cur);
		}
	}
	//남은 것들 처리
	while (top != -1) {
		answer[stack[top].idx] = 0;
		pop();
	}
	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) 
		scanf("%d", &arr[i]);
	
	int* ret = solution(n);

	//출력
	for (int i = 0; i < n; ++i)
		printf("%d\n", ret[i]);

	return 0;
}
