#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* stack;
int top = -1;

void push(int size, char data) {
	stack[++top] = data;

	top = top % size;
	return;
}

void pop(int size) {
	top--;
	top = top % size;

	return;
}

void solution(void) {
	char stick[100001] = { 0, };
	int result = 0;

	scanf("%s", stick);
	int size = strlen(stick);
	stack = (char*)malloc(sizeof(char) * size);
	for (int i = 0; i < size; ++i) {
		if (stick[i] == '(') 
			push(size, '(');
		
		else {
			pop(size);
			if (stick[i - 1] == '(') {
				result += (top + 1);
			}
			else
				result++;
		}
	}
	printf("%d", result);
	return;
}

int main(void) {
	solution();
	return 0;
}