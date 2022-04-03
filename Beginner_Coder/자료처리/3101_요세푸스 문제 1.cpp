#include <iostream>
#include <vector>
#include <queue>

using namespace std;



vector<int> solution(int n, int k) {
	vector<int> answer;
	queue<int> que;

	for (int i = 1; i <= n; ++i)
		que.push(i);

	while (!que.empty()) {
		// ���̰� 1�̸�
		if (que.size() == 1) {
			answer.push_back(que.front());
			que.pop(); // pop
			break;
		}

		// k - 1�� pop
		for (int i = 0; i < k - 1; ++i) {
			que.push(que.front());
			que.pop(); // pop
		}

		// �ֻ�� 
		answer.push_back(que.front());
		que.pop(); // pop;
	}

	return answer;
}

int main(void) {
	int n, k;

	cin >> n >> k;
	vector<int> ret = solution(n, k);
	for (int& r : ret)
		cout << r << ' ';
	return 0;
}