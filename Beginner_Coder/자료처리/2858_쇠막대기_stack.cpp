#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string stick) {
	int answer = 0; 
	int size = stick.length();

	stack<int> st; // 스택 선언
	for (int i = 0; i < size; ++i) {
		// 오픈 이면
		if (stick[i] == '(')
			st.push(1);

		// 클로즈가 나오면
		else {
			st.pop(); // pop
			if (stick[i - 1] == '(')
				answer += st.size();
			else
				answer++;
		}
	}

	return answer;
}

int main(void) {
	string stick;
	cin >> stick;

	int ret = solution(stick);
	cout << ret;
	return 0;
}
