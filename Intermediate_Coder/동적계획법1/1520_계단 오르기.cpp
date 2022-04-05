#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> steps;

//최댓값 반환
int Max(int a, int b) {
	return a > b ? a : b;
}

int solution(int n) {
	int answer = 0;
	dp.resize(n, 0);

	dp[0] = steps[0];
	dp[1] = steps[0] + steps[1];
	dp[2] = Max(steps[1] + steps[2], steps[0] + steps[2]);

	for (int i = 3; i < n; ++i) 
		dp[i] = steps[i] + Max(dp[i - 2], dp[i - 3] + steps[i - 1]);
	
	answer = dp[n - 1];
	return answer;
}

int main(void) {
	int n;
	cin >> n;
	steps.resize(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> steps[i];

	int ret = solution(n);
	cout << ret;
	return 0;
}
