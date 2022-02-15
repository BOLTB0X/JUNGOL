#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str, words = "";
	vector<string> v;
	getline(cin, str);

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			v.push_back(words);
			words = "";
		}
		else
			words += str[i];
	}

	if (words.length() != 0)
		v.push_back(words);

	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i] << '\n';

	return 0;
}