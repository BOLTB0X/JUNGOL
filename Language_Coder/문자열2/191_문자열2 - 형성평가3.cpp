#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string words[50];
	int idx = 0;

	while (1) {
		string tmp;
		cin >> tmp;

		if (tmp == "0")
			break;

		words[idx++] = tmp;
	}

	cout << idx << '\n';
	for (int i = 0; i < idx; i += 2)
		cout << words[i] << '\n';
	return 0;
}