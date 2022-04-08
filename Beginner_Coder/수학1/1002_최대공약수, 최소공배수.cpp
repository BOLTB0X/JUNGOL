#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

pair<int, int> solution(int n, int* arr) {
	pair<int, int> answer = { 0,0 };

	answer.first = arr[0];
	answer.second = arr[0];

	for (int i = 1; i < n; ++i) {
		answer.first = gcd(answer.first, arr[i]);
		answer.second = lcm(answer.second, arr[i]);
	}

	return answer;
}

int main(void) {
	int n;
	int* arr;

	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	pair<int, int> ret = solution(n, arr);
	cout << ret.first << ' ' << ret.second;
	delete[] arr;
	return 0;
}