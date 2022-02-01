#include <iostream>
#include <string>

using namespace std;

string solution(char str[][15]) {
	string answer = "";

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (str[j][i] == '.')
				continue;
			answer += str[j][i];
		}
	}
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char str[5][15];
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 15; ++j)
			str[i][j] = '.';
	}
	
	for (int i = 0; i < 5; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); ++j)
			str[i][j] = tmp[j];
	}
	

	string ret = solution(str);

	cout << ret << '\n';

	return 0;
}