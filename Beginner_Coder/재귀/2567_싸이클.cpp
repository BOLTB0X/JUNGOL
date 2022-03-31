#include <iostream>
#include <vector>

using namespace std;

vector<int> cnt(1001, 0);

// 재귀
void recursive_func(int n, int p, int number) {
	// 사이클 생기면 탈출
	if (cnt[number] == 2)
		return;

	cnt[number]++;
	recursive_func(n, p, (n * number) % p);
	return;
}

int solution(int n, int p) {
	int answer = 0;

	recursive_func(n, p, (n * n) % p);

	for (int i = 0; i <= 1000; ++i) {
		if (cnt[i] == 2)
			answer++;
	}

	return answer;
}
int main(void) {
	int n, p;

	cin >> n >> p;

	int ret = solution(n, p);
	cout << ret;

	return 0;
}
