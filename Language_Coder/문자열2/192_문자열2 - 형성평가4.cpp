#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	string words[50];
	int n, idx = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> words[i];

	sort(words, words + n);
	
	for (int i = 0; i < n; ++i)
		cout << words[i] << '\n';
	return 0;
}