#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MS 100001 //최대 길이

typedef struct {
	int idx, height;
} Building;

Building stack[MS];
int top = -1;

void push(Building data) {
	stack[++top] = data;
	return;
}

void pop(void) {
	top--;
	return;
}

int* solution(int n, int *arr) {
	int* answer = malloc(sizeof(int) * (n + 1));

	//각 배열을 반복
	for (int i = 0; i < n; ++i) {
		//스택이 비었다면
		if (top == -1) {
			Building b = { i, arr[i] };
			push(b);
		}

		else {
			//스택이 비어질때까지 스택의 최상단 원소의 길이가 배열보다 작다면
			//빌딩이 보인다는 것
			while (top != -1 && stack[top].height < arr[i]) {
				answer[stack[top].idx] = i + 1;
				pop(); //최상단을 빼줌
			}

			//연산 후 현재 빌딩 스택으로
			Building b = { i, arr[i] };
			push(b);
		}
	}

	//남은 것들은 보이는 빌딩이 없으므로
	//스택에 남은 빌딩들 0처리
	while (top != -1) {
		answer[stack[top].idx] = 0;
		pop(); //최상단을 빼줌
	}
	
	return answer;
}

int main(void) {
	int n;
	scanf("%d", &n);
	int arr[MS];

	for (int i = 0; i < n; ++i) 
		scanf("%d", &arr[i]);
	
	int* ret = solution(n, arr);

	//출력
	for (int i = 0; i < n; ++i)
		printf("%d\n", ret[i]);

	return 0;
}
