#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int num[11];
int top = -1;
char op[4] = { '+','-','*','/' };
char input[11];

int pop(void) {
	int ret = num[top--];
	return ret;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) 
		scanf(" %c", &input[i]);
	
	for (int i = 0; i < n; ++i) {
		if (input[i] >= '0' && input[i] <= '9')
			num[++top] = input[i] - '0';
		else {
			if (input[i] == '+') {
				num[top]  += pop();
			}

			else if (input[i] == '-') {
				num[top] -= pop();
			}

			else if (input[i] == '*') {
				num[top] *= pop();
			}

			else if (input[i] == '/') {
				num[top] /= pop();
			}
		}
	}

	printf("%d\n", num[0]);
	return;
}

int main(void) {
	solution();
	return 0;
}