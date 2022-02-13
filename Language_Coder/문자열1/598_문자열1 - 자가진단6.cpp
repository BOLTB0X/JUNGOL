#include <iostream>

using namespace std;

int main(void) {
	char asc;

	while (1) {
		cin >> asc;
        if (asc >= '0' && asc <= '9')
            cout << (int)asc << '\n';
        else if (asc >= 'a' && asc <= 'z')
            cout << asc << '\n';
        else if (asc >= 'A' && asc <= 'Z')
            cout << asc << "\n";
        else
            break;
	}

    return 0;
}