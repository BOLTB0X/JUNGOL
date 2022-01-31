#include <iostream>
#include <string>

using namespace std;

int solution(string stick) {
	int answer = 0;
	int size = stick.length();
	int open_cnt = 0;
	bool flag = false;

	for (int i = 0; i < size; ++i) {
		if (stick[i] == '(') {
			open_cnt++;
			flag = false;
		}
		else if (stick[i] == ')') {
			if (!flag) {
				--open_cnt;
				answer += open_cnt;
				flag = true;
			}
			else {
				answer += 1;
				open_cnt--;
			}
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