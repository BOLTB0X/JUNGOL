#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int check[10000] = { 0, };

//에라토스테네체 0:소수 O 1:소수 X
void eratosthenes(void) {
	int number;
	check[0] = check[1] = 1;
	for (int i = 2; i*i < 10000; ++i) {
		if (check[i] == 1)
			continue;
		for (int j = i + i; j < 10000; j += i)
			check[j] = 1;
	}

	return;
}

//자리수 비교
bool check_Number_cnt(int number1, int number2) {
	int cnt = 0;

	//어차피 4자리 이므로
	for (int i = 0, j = 10; i < 4; ++i) {
		if (number1 % j != number2 % j)
			cnt++;
		number1 /= j;
		number2 /= j;
	}

	return cnt == 1;

}

//BFS
int BFS(bool* visited, int start, int destination) {
	queue<pair<int, int>> que;
	que.push({ start, 0 });
	visited[start] = true;

	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();

		if (cur.first == destination)
			return cur.second;

		for (int next = 1000; next < 9999; ++next) {
			if (visited[next])
				continue;
			if (check[next] == 1)
				continue;
			if (!check_Number_cnt(cur.first, next))
				continue;

			visited[next] = true;
			que.push({ next, cur.second + 1 });
		}
	}

	return -1;
}

int solution(int start, int destination) {
	int answer = 0;
	eratosthenes();
	bool visited[9999] = { false, };

	answer = BFS(visited, start, destination);

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int start, destination;
	cin >> start >> destination;

	int ret = solution(start, destination);
	cout << ret;
	return 0;
}