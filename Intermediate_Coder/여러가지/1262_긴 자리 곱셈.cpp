#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string n1, string n2) {
	vector<int> answer; // 깋이가 너무 길어서 벡터로 반환
	int len1 = n1.length(), len2 = n2.length();
	int alen = len1 + len2 - 1; // 총 연산 길이
	answer.resize(alen, 0); // 길이 할당

	for (int i = 0; i < len1; ++i) {
		for (int j = 0; j < len2; ++j) 
			answer[i + j] += (n1[i] - '0') * (n2[j] - '0');
	}

	// 올림처리
	for (int i = alen - 1; i > 0; --i) {
		answer[i - 1] += answer[i] / 10; // 올림
		answer[i] %= 10; // 1의 자리만
	}
	
	return answer;
}

int main(void) {
	string n1, n2;

	while (1) {
		int flag1 = 0, flag2 = 0;
		cin >> n1;
		// 탈출 조건
		if (n1 == "0")
			return 0;

		cin >> n2;
		if (n1 == "0" || n2 == "0")
			cout << '0' << '\n';

		else {
			if (n1[0] == '-') {
				flag1 = 1;
				n1 = n1.substr(1, n1.length() - 1); // -삭제
			}

			if (n2[0] == '-') {
				flag2 = 1;
				n2 = n2.substr(1, n2.length() - 1); // -삭제
			}

			vector<int> ret = solution(n1, n2);
			if ((flag1 == 1 && flag2 == 0) || (flag1 == 0 && flag2 == 1))
				cout << '-';
			for (int& r : ret)
				cout << r;
			cout << "\n";
		}
	}

	return 0;
}