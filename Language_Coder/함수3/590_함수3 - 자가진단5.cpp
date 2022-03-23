#include <iostream>

using namespace std;

int com[10];

void recursive_func(int n, int level) {
	if (level > n) {
		for (int i=1; i<= n;++i)
			cout << com[i] << ' ';
		cout << '\n';
		return;
	}
	
	for (int i= com[level - 1]; i <= 6; ++i) {
		com[level] = i;
		recursive_func(n, level + 1);
	}
	
	return;
	
}

int main(void) {
	int n;
	cin >> n;
	
	com[0] = 1;
	recursive_func(n, 1);
	
	return 0;
}
