#include <iostream>
#include <vector>

using namespace std;

int is_Group_Possible(int n, int m, vector<int>& beads, int mid) {
	int tot = 0, g_cnt = 1;

	//그룹화 테스팅
	for (int& b : beads) {
		tot += b;

		//중앙값보다 커지면
		if (tot > mid) {
			tot = b; // 중앙으로 변경
			g_cnt++; // 카운팅
		}
	}

	return g_cnt <= m;
}

int solution(int n,int m, vector<int>& beads) {
	int answer = 0;
	//parametric search를 위한 
	int left = 0, right = 0, mid;
	
	//스타트 셋팅
	for (int& b : beads) {
		left = left < b ? b : left;
		right += b;
	}

	while (left <= right) {
		mid = (left + right) / 2;

		if (is_Group_Possible(n, m, beads, mid) == 1)
			right = mid - 1;
		else
			left = mid + 1;
	}

	//대값이 최소가 되도록 M개의 그룹으로 나누었을 때 -> left
	answer = left;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> beads;

	cin >> n >> m;
	beads.resize(n, 0);
	
	for (int i = 0; i < n; ++i) 
		cin >> beads[i];
	
	int ret = solution(n,m, beads);
	cout << ret;
	return 0;
}