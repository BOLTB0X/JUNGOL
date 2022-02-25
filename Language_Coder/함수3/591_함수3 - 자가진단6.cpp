#include <iostream>

using namespace std;

int recursive_func(int n) {
	if (n <= 1) 
		return 1;
	//(N/2)번째 수와 (N-1)번째 수의 합
	return recursive_func(n / 2) + recursive_func(n - 1);
}

int main(void) {
	int n;
	cin >> n;

	cout << recursive_func(n);
	
	return 0;
}
