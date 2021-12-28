#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//배열로는 한 곳을 비여야함
int queue[101];
int head = 0, tail = 0, qsize = 0;

int is_Empty(void) {
	if (head == tail)
		return 1;
	return 0;
}

//push
void enqueue(int data) {
	queue[tail++] = data;
	qsize++;
	return;
}

//pop
int dequeue(void) {
	int tmp = queue[head++];
	qsize--;

	return tmp;
}

int is_Full(void) {
	if (tail + 1 == head)
		return 1;
	return 0;
}

void solution(void) {
	int n;
	char cmd;
	int data;
	scanf("%d", &n);

	for (int j = 0; j < n; ++j) {
		scanf(" %c", &cmd);

		if (cmd == 'i') {
			scanf(" %d", &data);
			enqueue(data);
		}

		else if (cmd == 'o') {
			if (is_Empty())
				printf("empty\n");
			else
				printf("%d\n", dequeue());
		}

		else if (cmd == 'c') 
			printf("%d\n", qsize);
	}
}

int main(void) {
	solution();
	return 0;
}