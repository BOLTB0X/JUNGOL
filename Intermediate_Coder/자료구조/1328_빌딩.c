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

void solution(int n) {
	int* answer = malloc(sizeof(int) * (n + 1));
	for (int i = 0; i < n; ++i) {

		if (top == -1) {
			Node data = { i + 1, arr[i] };
			push(data);
		}

		else {
			while (top != -1 && stack[top].height < arr[i]) {
				answer[stack[top].idx] = i + 1;
				pop();
			}
		}
		Node data = { i + 1, arr[i] };
		push(data);
	}
	while (top != -1) {
		answer[stack[top].idx] = 0;
		pop();
	}

	for (int i = 1; i <= n; ++i)
		printf("%d\n", answer[i]);
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) 
		scanf("%d", &arr[i]);
	
	solution(n);

	return 0;
}