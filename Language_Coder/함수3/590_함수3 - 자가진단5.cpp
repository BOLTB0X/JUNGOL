#include <iostream>

using namespace std;

int per[10];

void recursive_func(int n, int level) {
	if (level > n) {
		for (int i=1; i<= n;++i)
			cout << per[i] << ' ';
		cout << '\n';
		return;
	}
	
	for (int i= per[level - 1]; i <= 6; ++i) {
		per[level] = i;
		recursive_func(n, level + 1);
	}
	
	return;
	
}

int main(void) {
	int n;
	cin >> n;
	
	per[0] = 1;
	recursive_func(n, 1);
	
	return 0;
}
