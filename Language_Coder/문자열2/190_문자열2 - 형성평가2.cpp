#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string words[5] = { "flower", "rose", "lily", "daffodil", "azalea" };
	int cnt = 0;
	char ch;
	cin >> ch;

	for (string& word : words) {
		if (word[1] == ch || word[2] == ch) {
			cout << word << '\n';
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}