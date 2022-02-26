#include <iostream>
#include <string>

using namespace std;

int solution(string stick) {
	int answer = 0;
	int open_cnt = 0;
	bool flag = false;

	for (char &s: stick) {
		if (s == '(') {
			open_cnt++;
			flag = 0;
		}
		 // )을 만난 경우
		else if (flag == 0 && s == ')') { //바로 앞이 ( 인 경우
				answer += (--open_cnt);
				flag = 1;
		}
		else if (flag == 1 && s == ')') {
			answer++; //바로 앞이 같은 )이므로
			open_cnt--;
		}
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string stick;
	cin >> stick;
	int ret = solution(stick);

	cout << ret;
	return 0;
}
