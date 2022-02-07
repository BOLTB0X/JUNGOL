#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int data, cnt;
} NUMBER;

NUMBER que[10000];
int head = 0, tail = 0;

int check[10000]; //소수 채크용
int visited[10000]; //방문리스트

void enqueue(NUMBER data) {
	que[tail++] = data;
	tail = tail % 10000;
	return;
}

void dequeue(void) {
	head++;
	head = head % 10000;
	return;
}

//자리수 체크
int check_Digit_cnt(int number1, int number2) {
	int cnt = 0;
	//어차피 4자리수 이므로 
	for (int i = 0, j = 10; i < 4; ++i) {
		if (number1 % j != number2 % j)
			cnt++;
		number1 /= j;
		number2 /= j;
	}

	return cnt == 1;
}

//너비우선탐색
int BFS(int start, int destination) {
	NUMBER data = { start, 0 };
	enqueue(data);
	visited[start] = 1;

	while (head != tail) {
		int cur = que[head].data;
		int cnt = que[head].cnt;
		dequeue();

		if (cur == destination)
			return cnt;

		for (int next = 1000; next < 10000; ++next) {
			//재방문
			if (visited[next] == 1)
				continue;
			//소수가 아닌 경우
			if (check[next] == 1)
				continue;
			if (check_Digit_cnt(cur, next) == 0)
				continue;

			visited[next] = 1;
			NUMBER n = { next, cnt + 1 };
			enqueue(n);
		}
	}
	return -1;
}

int solution(int num1, int num2) {
	int answer = 0;

	//에라토스테네체 이용 소수를 1로 체크
	for (int i = 2; i * i <= 10000; ++i) {
		if (check[i] == 1)
			continue;
		for (int j = i + i; j < 10000; j += i)
			check[j] = 1;
	}

	answer = BFS(num1, num2);

	return answer;
}

int main(void) {
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	int ret = solution(num1, num2);
	printf("%d", ret);
	return 0;
}