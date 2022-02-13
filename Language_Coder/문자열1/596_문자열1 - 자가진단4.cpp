#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	int n;
	cin >> str >> n;

	if (str.length() > n) 
		str = str.substr(str.length() - n, n);
	
	reverse(str.begin(), str.end());

	cout << str;
	return 0;
}