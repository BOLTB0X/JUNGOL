#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution(void) {
	vector<string> v;
	string input;
	
	getline(cin, input);

	string tmp = "";
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == ' ') {
			v.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += input[i];
		}
	}
	v.push_back(tmp);

	for (int i = 0; i < v.size(); i += 2) {
		cout << v[i] << '\n';
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}