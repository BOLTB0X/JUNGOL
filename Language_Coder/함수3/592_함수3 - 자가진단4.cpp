#include <iostream>

using namespace std;

int recursive_func(int n) {
	if (n == 0) 
		return 0;
	
	return (n % 10) * (n % 10)+ recursive_func(n/10);
	
}

int main(void) {
	int n;
	cin >> n;
	
	cout << recursive_func(n);
	
	return 0;
}
