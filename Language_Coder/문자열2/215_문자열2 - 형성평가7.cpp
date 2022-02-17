#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string st1, st2;
	string num1 = "", num2 = "";

	cin >> st1 >> st2;
	for (int i = 0; i < st1.length(); ++i) {
		if (st1[i] >= '0' && st1[i] <= '9')
			num1 += st1[i];
		else
			break;
	}
	for (int i = 0; i < st2.length(); ++i) {
		if (st2[i] >= '0' && st2[i] <= '9')
			num2 += st2[i];
		else
			break;
	}
	
	cout << stoi(num1) * stoi(num2);
	return 0;
}