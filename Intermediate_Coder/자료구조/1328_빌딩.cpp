#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(int n, vector<int>& bulidings) {
	vector<int> answer(n, 0);
	stack<pair<int, int>> h;

	for (int i = 0; i < n; ++i) {
		// 스택이 비었다면
		if (h.empty()) 
			h.push({ i,bulidings[i] });

		else {
			//스택이 비어질때까지 스택의 최상단 원소의 길이가 배열보다 작다면
			//빌딩이 보인다는 것
			while (!h.empty() && h.top().second < bulidings[i]) {
				answer[h.top().first] = i + 1;
				h.pop();
			}

			// 연산 후 현재 빌딩 스택으로
			h.push({ i,bulidings[i] });
		}

		
	}
	//남은 것들은 보이는 빌딩이 없으므로
	//스택에 남은 빌딩들 0처리
	while (!h.empty()) {
		answer[h.top().first] = 0;
		h.pop();
	}

	return answer;
}

int main(void) {
	int n;
	vector<int> bulidings;

	cin >> n;
	bulidings.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> bulidings[i];

	vector<int> ret = solution(n, bulidings);
	for (int& r : ret)
		cout << r << '\n';

	return 0;
}