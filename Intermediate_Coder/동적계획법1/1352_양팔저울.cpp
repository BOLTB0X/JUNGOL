#include <iostream>
#include <vector>

using namespace std;

int dp[35][40005];

//���񰪹�ȯ
int Abs(int a) {
	return a < 0 ? -a : a;
}

void solution(int n, int m, vector<int>& weights, vector<int>& beads) {
	//dp���̺� �ʱ�ȭ
	vector<int> tot(n + 1, 0);

	//�հ� ����
	for (int i = 1; i <= n; ++i) 
		tot[i] = tot[i - 1] + weights[i];
	
	//���Ҿ�
	for (int i = 1; i <= n; ++i) {
		//���� ���Դ� ��������
		dp[i][weights[i]] = 1;

		//��� �����ߴ� ���Ը���, �̹� �߸� ����, ����, �̻��
		for (int j = 1; j <= tot[i - 1]; ++j) {
			if (dp[i - 1][j] == 1) {
				dp[i][j] = 1;
				dp[i][j + weights[i]] = 1; //�ݴ��� �̿�
				dp[i][Abs(j - weights[i])] = 1; //���� �߸� ���� ���Կ� ����
			}
		}
	}

	for (int i = 1; i <= m; ++i) {
		if (dp[n][beads[i]] == 1)
			cout << 'Y' << ' ';
		else
			cout << 'N' << ' ';
	}
	
	return ;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	vector<int> weights, beads;

	cin >> n;
	weights.resize(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> weights[i];

	cin >> m;
	beads.resize(m + 1, 0);
	for (int i = 1; i <= m; ++i)
		cin >> beads[i];

	solution(n, m, weights, beads);
	
	return 0;
}