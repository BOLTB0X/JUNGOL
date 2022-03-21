#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct {
	int number, cnt;
} Bus;

Bus que[100000];
int fr = 0, re = 0;

void enqueue(Bus data) {
	que[re++] = data;
	return;
}

Bus dequeue(void) {
	return que[fr++];
}

int prime[10000]; // 소수이면 1

// 에라토스테네체
void eratos(void) {
	prime[0] = prime[1] = 1;

	for (int i = 2; i *i < 10000; ++i) {
		// 이미 지워진 경우
		if (prime[i] == 1)
			continue;

		for (int j = i + i; j < 10000; j += i)
			prime[j] = 1;
	}

	return;
}

// 번호가 1만 차이나는가?
int is_Process(int num1, int num2) {
	int cnt = 0;

	// 어차피 네자리 이므로
	for (int i = 0; i < 4; ++i) {
		// 다르다면
		if ((num1 % 10) != (num2 % 10))
			cnt++;

		num1 /= 10;
		num2 /= 10;
	}

	return cnt == 1;
}

// 너비우선 탐색
int BFS(int number1, int number2) {
	vector<int> visited(10000, 0); //방문리스트 생성 및 초기화

	visited[number1] = 1; // 방문처리
	enqueue({ number1, 0 });

	while (fr < re) {
		Bus cur = dequeue(); 

		// 목적지에 도달했다면
		if (cur.number == number2) 
			return cur.cnt;
		
		for (int i = 1000; i <= 9999; ++i) {
			// 재방문
			if (visited[i] == 1)
				continue;
				
			// 소수가 아니라면
			if (prime[i] == 1)
				continue;

			// 이동 조건이 맞느가?
			if (is_Process(cur.number, i) == 0)
				continue;

			visited[i] = 1;
			enqueue({ i, cur.cnt + 1 });
		}
	}

	return -1;
}

int solution(int number1, int number2) {
	int answer = 0;
	memset(prime, 10000, 0); // 초기화
	// 소수 체크
	eratos();
	answer = BFS(number1, number2);

	return answer;
}

int main(void) {
	int number1, number2;

	cin >> number1 >> number2;

	int ret = solution(number1, number2);
	cout << ret;

	return 0;
}
