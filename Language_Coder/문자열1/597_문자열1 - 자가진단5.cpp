#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str1, str2;
	cin >> str1 >> str2;

	cout << str1.length() + str2.length();
	return 0;
}