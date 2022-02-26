#include <iostream>
#include <string>
#include <stack>
using namespace std;


int solution(string stick) {
	int answer = 0;
	int size = stick.length(); //����
	stack<int> st;
	
	for (int i = 0; i < size; ++i) {
		if (stick[i] == '(')
			st.push(0); //top������ �˸� �ǹǷ�

		else { // ��� ��ȣ�� ���� �ٸ�
			st.pop(); // ��
			if (stick[i - 1] == '(') //�ٷ� ���� �����̸�
				answer += st.size(); //top == size
			else // ')'�� ��ȣ�� �����̿��ٸ�
				answer++;
		}
	}

	return answer;
}

int main(void) {
	//�ʱ�ȭ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string stick;
	cin >> stick;

	int ret = solution(stick);

	cout << ret;
	return 0;
}