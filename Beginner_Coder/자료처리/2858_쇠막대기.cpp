#include <iostream>
#include <stack>
#include <string>

using namespace std;

void solution(void) {
	string stick;
	stack<char> st;

	cin >> stick;

	int result = 0;

	for (int i = 0; i < stick.length(); ++i) {
		if (stick[i] == '(')
			st.push('(');
		else {
			st.pop();
			if (stick[i - 1] == '(')
				result += st.size();
			else
				result++;
		}
	}
	
	cout << result << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}