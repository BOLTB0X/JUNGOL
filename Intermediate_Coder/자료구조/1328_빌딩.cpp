#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(int n, vector<int>& bulidings) {
	vector<int> answer(n, 0);
	stack<pair<int, int>> st;

	for (int i = 0; i < n; ++i) {
		// 스택이 비었다면
		if (st.empty()) 
			st.push({ i,bulidings[i] });
		
		else {
			while (!st.empty() && bulidings[i] > st.top().second) {
				answer[st.top().first] = (i + 1);
				st.pop();
			}

			st.push({ i,bulidings[i] });
		}
	}

	while (!st.empty()) {
		answer[st.top().first] = 0;
		st.pop();
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
