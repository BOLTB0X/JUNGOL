#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[100];
int top = -1;

int is_Full(void) {
	//가득차있다면
	if (top >= 99)
		return 1;
	return 0;
}

int is_Empty(void) {
	if (top == -1) 
		return 1;
	
	return 0;
}

void push(int data) {
	if (!is_Full()) 
		stack[++top] = data;
	return;
}

int pop(void) {
	if (!is_Empty()) {
		int tmp = stack[top--];
		return tmp;
	}
	return -1;
}

void solution(void) {
	int n;
	char cmd;
	int data;
	scanf("%d", &n);

	for (int j=0; j< n; ++j) {
		scanf(" %c", &cmd);

		if (cmd == 'i') {
			scanf(" %d", &data);
			push(data);
		}

		else if (cmd == 'o') {
			if (is_Empty())
				printf("empty\n");
			else
				printf("%d\n", pop());
		}

		else if (cmd == 'c')
			printf("%d\n", top + 1);
	}

	return;
}

int main(void) {
	solution();
	return 0;
}
