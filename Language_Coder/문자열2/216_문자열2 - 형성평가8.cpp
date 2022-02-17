#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string st1;

	while (1) {
		cin >> st1;
		if (st1 == "END")
			break;
		reverse(st1.begin(), st1.end());
		cout << st1 << '\n';
	}
	return 0;
}