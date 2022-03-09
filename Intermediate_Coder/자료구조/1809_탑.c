#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MS 500001 //�ִ� ����

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

	//�������ǿ� ����
	for (int i = n - 1; i >= 0; --i) {
		//������ ����ٸ�
		if (top == -1) {
			Transter t = { i, arr[i] };
			push(t);
		}

		else {
			//������ ������� �ʰ� ���� �۽űⰡ ���ÿ��Ҹ� ���� �� �ִٸ�
			while (top != -1 && stack[top].height < arr[i]) {
				answer[stack[top].idx] = i + 1;
				pop();
			}

			//���� �۽ű⸦ �ٽ� Ǫ��
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
	//���
	for (int i = 0; i < n; ++i)
		printf("%d ", ret[i]);
	
	free(arr);
	return 0;
}