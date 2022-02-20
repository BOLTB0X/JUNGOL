#include <iostream>
#include <vector>

using namespace std;

vector<int> result(1001, 0);

//DFS 이용
void DFS(int n, int m, int number) {
	//싸이클이 생기면 탈출
	if (result[number] == 2)
		return;
	result[number]++;
	DFS(n, m, (number * n) % m);
	return;
}

int solution(int n, int m) {
	int answer = 0;

	result[n] = 1;
	DFS(n, m, (n * n) % m);

	for (int i = 0; i <= 1001; ++i) {
		if (result[i] == 2)
			answer++;
	}

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	int ret = solution(n, m);
	cout << ret;
	return 0;
}
