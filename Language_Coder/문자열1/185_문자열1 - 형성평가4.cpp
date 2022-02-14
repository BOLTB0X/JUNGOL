#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	char target;
	cin >> str;
	cin >> target;
	
	for (int i=0; i<str.length();++i) {
		if (str[i] == target) {
			cout << i;
			return 0;
		}
	}
	
	cout << "No";
	return 0;
}
