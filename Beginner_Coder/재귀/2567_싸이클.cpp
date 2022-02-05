#include <iostream>
#include <vector>

using namespace std;

void recur(vector<int>& v, int n, int m, int number) {
	if (v[number] == 2)
		return;
	v[number]++;
	recur(v, n, m, (number * n) % m);
	return;
}

int solution(int n, int m) {
	vector<int> v(10001, 0);
	int cycle = 0;
	recur(v, n, m, n);

	for (auto& a : v) {
		if (a == 2)
			cycle++;
	}

	return cycle;
}

int main(void) {
	//ÃÊ±âÈ­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	int ret = solution(n, m);
	cout << ret;
	return 0;
}