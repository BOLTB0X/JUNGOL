#include <iostream>

using namespace std;

int main(void) {
	int n;
	while (1) {
		cout << "ASCII code =? ";
		cin >> n;
		if (n < 33 || 127 < n)
			break;
		cout << (char)n << '\n';
	}

	return 0;
}