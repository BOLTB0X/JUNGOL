#include <iostream>

using namespace std;

int arr[41];

pair<int, int> solution(int n, int m) {
	pair<int, int> answer = { 0, 0 };

	for (int i = 0; i < n; ++i) {
		if (m >= arr[i] && m % arr[i] == 0)
			answer.first += arr[i];
		if (m <= arr[i] && arr[i] % m == 0)
			answer.second += arr[i];
	}

	return answer;
}

int main(void) {
	int n, m;
	
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> m;

	pair<int, int> ret = solution(n, m);
	cout << ret.first << '\n' << ret.second;
	return 0;
}