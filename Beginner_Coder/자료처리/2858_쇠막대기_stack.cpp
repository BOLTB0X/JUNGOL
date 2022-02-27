#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string stick) {
	int answer = 0; 
	int size = stick.length();

	stack<int> st; //연산을 위한 스택 선언

	for (int i = 0; i < size; ++i) {
		if (stick[i] == '(') 
			st.push(1); // 스택 삽입
		// ')'을 만나는 경우
		else {
			st.pop(); 
			//바로전이 오픈 기호라면
			if (stick[i - 1] == '(') 
				answer += (st.size());
			//바로 전이 클로즈라면
			else
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
