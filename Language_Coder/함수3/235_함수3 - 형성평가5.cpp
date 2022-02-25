#include <iostream>

using namespace std;

int cnt = 0;

void recursive_func(int n, int level) {
	if (n == 1) {
		cnt = level;
		return;
	}
	if (n % 2 == 0)
		recursive_func(n/2, level + 1);
	else
		recursive_func(n/3, level + 1);
	return;
}

int main(void) {
	int n;
	cin >> n;
	
	recursive_func(n, 0);
	cout << cnt;
	
	return 0;
}
