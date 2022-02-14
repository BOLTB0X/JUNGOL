#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	
	cin >> str;
	
	for (int i=0; i<5;++i) {
		cout << str[i];
	}
	
	return 0;
}
