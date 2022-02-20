#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> steps;

//최댓값 반환
int MAX(int a, int b) {
	return a > b ? a : b;
}

void solution(int n) {
	dp.resize(n + 1, 0);

	dp[1] = steps[1];
	dp[2] = steps[1] + steps[2];
	dp[3] = MAX(steps[1] + steps[3], steps[2] + steps[3]);

	//보텀업
	//현재 계단을 밟을 지 말지 결정
	//현재 계단을 더할 것 중에 연속 3칸은 안 되므로
	// 세 칸 전 기록 + 현재 -1 , 두칸 전 기록 
	for (int i = 4; i <= n; ++i) 
		dp[i] = steps[i] + MAX(dp[i - 3] + steps[i - 1], dp[i - 2]);
	
	cout << dp[n];
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	steps.resize(n + 1, 0);

	for (int i = 1; i <= n; ++i)
		cin >> steps[i];

	solution(n);

	return 0;
}
