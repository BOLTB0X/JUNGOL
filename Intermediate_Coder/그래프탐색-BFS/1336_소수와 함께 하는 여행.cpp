#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
	int number, cnt;
} Info;

int check[10000] = { 0, };

Info que[10000];
int fr = 0, re = 0;

void enqueue(Info data) {
	que[re++] = data;
	return;
}

Info dequeue(void) {
	return que[fr++];
}

//에라토스테네체
void eratos(void) {
	check[0] = check[1] = 1;
	for (int i = 2; i * i <= 9999; ++i) {
		if (check[i] == 1) //소수X 체크
			continue;
		for (int j = i + i; j <= 9999; j += i) 
			check[j] = 1;
	}
	return;
}

//자리수로 체크
int check_Number(int cur, int next) {
	int cnt = 0;

	//4자리 숫자로 고정
	for (int i = 0, j = 10; i < 4; ++i) {
		if ((cur % j) != (next % j))
			cnt++;
		cur /= j;
		next /= j;
	}

	return cnt == 1;
}

//너비우선 탐색
int BFS(int number1, int number2, vector<int>& visited) {
	enqueue({ number1 ,0 });
	visited[number1] = 1;

	while (fr < re) {
		Info cur = dequeue();

		if (cur.number == number2) 
			return cur.cnt;
		
		for (int next = 1000; next <= 9999; ++next) {
			//재방문 체크
			if (visited[next] == 1)
				continue;

			//소수가 아니라면
			if (check[next] == 1)
				continue;

			//문제 조건
			if (check_Number(cur.number, next) == 0)
				continue;
			
			visited[next] = 1;
			enqueue({ next, cur.cnt + 1 });
		}
	}

	return -1;
}

int solution(int number1, int number2) {
	int answer = 0;
	eratos(); //소수 체크
	vector<int> visited(10000, false);

	answer = BFS(number1, number2, visited);

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int number1, number2;
	cin >> number1 >> number2;
	
	int ret = solution(number1, number2);
	cout << ret;
	
	return 0;
}
