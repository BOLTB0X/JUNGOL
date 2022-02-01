#include <iostream>
#include <string>

using namespace std;

int is_String(string str, int idx) {
	if (str[idx] == 'K' && str[idx + 1] == 'O' && str[idx + 2] == 'I') 
		return 1;
	else if (str[idx] == 'I' && str[idx + 1] == 'O' && str[idx + 2] == 'I') 
		return 1;
	return 0;
}

pair<int,int> solution(string str) {
	pair<int, int> answer;
	answer.first = 0;
	answer.second = 0;

	int size = str.length();

	for (int i = 0; i < size - 2; ++i) {
		if (str[i] == 'K')
			answer.first += is_String(str, i);
		else if (str[i] == 'I')
			answer.second += is_String(str, i);
	}

	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	pair<int,int> ret = solution(str);

	cout << ret.first << '\n';
	cout << ret.second << '\n';

	return 0;
}