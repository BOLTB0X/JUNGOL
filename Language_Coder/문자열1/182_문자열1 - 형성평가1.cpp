#include <iostream>

using namespace std;

int abs(int a) {
	return a < 0 ? -a : a;
}

int main(void) {
	char a,b;
	
	cin >> a >> b;
	
	cout << (int)(a+b) << '\n';
	cout << abs((int)(a-b));
	
	return 0;
}
