#include <iostream>
#include <string>
using namespace std;

void solution(void) {
	string str1;
	string str2;

	getline(cin, str1);
	getline(cin, str2);

	if (str1.length() > str2.length()) {
		cout << str2 << '\n';
		cout << str1 << '\n';
	}
	else {
		cout << str1 << '\n';
		cout << str2 << '\n';
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}