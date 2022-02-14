#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	
	cin >> str;
	
	for (int i=0; i<str.length();++i) {
		if (str[i] >= 65 && str[i] <= 90)
			cout << (char)(str[i] + 32);
		else if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57))
			cout << (char)str[i];
	}
	
	return 0;
}
