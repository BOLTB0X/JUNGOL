#include <iostream>

using namespace std;

int arr[10];

void recursive_func(int n, int m, int level) {
	if (n == level) {
		int tot = 0;
		for (int i = 0; i < n; ++i)
			tot += arr[i];
		
		if (tot == m) {		
			for (int i = 0; i < n; ++i) 
				cout << arr[i] << ' ';
			cout << '\n';
		}
		return;
	}
	
	for (int i = 1; i <= 6; ++i) {
		arr[level] = i;
		recursive_func(n, m, level + 1);
	}
	
	return;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	
	recursive_func(n, m, 0);
	
	return 0;
}
