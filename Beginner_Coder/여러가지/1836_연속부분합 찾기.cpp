#include <iostream>

using namespace std;

int arr[100001];

int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer = -101;
	int tot = 0;

	for (int i = 1; i <= n; ++i) {
		// 합이 0보다 작아지면 연속 시작점 변경
		if (tot < 0)
			tot = arr[i];
		else {
			tot += arr[i];
			answer = Max(answer, tot); // 더해질때마다 변경
		}
	}
	answer = Max(answer, tot); // 더해질때마다 변경
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; ++i) 
		cin >> arr[i];
	
	int ret = solution(n);
	cout << ret;

	return 0;
}