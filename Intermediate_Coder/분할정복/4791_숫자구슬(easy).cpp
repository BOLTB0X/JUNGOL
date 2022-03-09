#include <iostream>
#include <vector>

using namespace std;

int is_Group_Possible(int n, int m, vector<int>& beads, int mid) {
	int tot = 0, g_cnt = 1;

	//�׷�ȭ �׽���
	for (int& b : beads) {
		tot += b;

		//�߾Ӱ����� Ŀ����
		if (tot > mid) {
			tot = b; // �߾����� ����
			g_cnt++; // ī����
		}
	}

	return g_cnt <= m;
}

int solution(int n,int m, vector<int>& beads) {
	int answer = 0;
	//parametric search�� ���� 
	int left = 0, right = 0, mid;
	
	//��ŸƮ ����
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

	//�밪�� �ּҰ� �ǵ��� M���� �׷����� �������� �� -> left
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