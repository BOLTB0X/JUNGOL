#include <iostream>

using namespace std;

int arr[101];

void recursive_func(int n, int level) {
	if (n < level)
		return;
	
	arr[level] = (arr[level - 1] * arr[level - 2]) % 100;
	recursive_func(n, level + 1);
	return;
}

int main(void) {
	int n;
	
	cin >> n;

	arr[1] = 1;
	arr[2] = 2;
	
	recursive_func(n, 3);
	cout << arr[n];
	
	return 0;
}
