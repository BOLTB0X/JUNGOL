#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(int n, vector<int>& bulidings) {
	vector<int> answer(n, 0);
	stack<pair<int, int>> h;

	for (int i = 0; i < n; ++i) {
		// ������ ����ٸ�
		if (h.empty()) 
			h.push({ i,bulidings[i] });

		else {
			//������ ����������� ������ �ֻ�� ������ ���̰� �迭���� �۴ٸ�
			//������ ���δٴ� ��
			while (!h.empty() && h.top().second < bulidings[i]) {
				answer[h.top().first] = i + 1;
				h.pop();
			}

			// ���� �� ���� ���� ��������
			h.push({ i,bulidings[i] });
		}

		
	}
	//���� �͵��� ���̴� ������ �����Ƿ�
	//���ÿ� ���� ������ 0ó��
	while (!h.empty()) {
		answer[h.top().first] = 0;
		h.pop();
	}

	return answer;
}

int main(void) {
	int n;
	vector<int> bulidings;

	cin >> n;
	bulidings.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> bulidings[i];

	vector<int> ret = solution(n, bulidings);
	for (int& r : ret)
		cout << r << '\n';

	return 0;
}