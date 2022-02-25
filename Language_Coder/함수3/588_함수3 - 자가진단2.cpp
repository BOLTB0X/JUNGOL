#include <iostream>

using namespace std;

void recursive_func(int n) {
	if (n == 0) 
		return;
	cout << n << ' ';
	recursive_func(n - 1);
	return;
}

int main(void) {
	int n;
	cin >> n;
	
	recursive_func(n);
	
	return 0;
}
