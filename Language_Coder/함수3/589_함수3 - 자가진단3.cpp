#include <iostream>

using namespace std;

int recursive_func(int n) {
	if (n == 0) 
		return 0;
	return n + recursive_func(n - 1);
	
}

int main(void) {
	int n;
	cin >> n;
	
	cout << recursive_func(n);
	
	return 0;
}
