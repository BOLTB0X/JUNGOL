#include <iostream>
#include <string>
#include <stack>
using namespace std;


int solution(string stick) {
	int answer = 0;
	int size = stick.length(); //길이
	stack<int> st;
	
	for (int i = 0; i < size; ++i) {
		if (stick[i] == '(')
			st.push(0); //top갯수만 알면 되므로

		else { // 딛는 괄호를 만난 다면
			st.pop(); // 팝
			if (stick[i - 1] == '(') //바로 전이 열림이면
				answer += st.size(); //top == size
			else // ')'는 기호가 연속이였다면
				answer++;
		}
	}

	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string stick;
	cin >> stick;

	int ret = solution(stick);

	cout << ret;
	return 0;
}