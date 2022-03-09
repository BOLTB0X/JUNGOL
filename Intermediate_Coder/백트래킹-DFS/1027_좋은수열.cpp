#include <iostream>
#include <string>
#include <vector>

using namespace std;

int flag;
string result;

//좋은 수열인지 판단
int is_Good_seq(string str) {
	int size = str.length();

	//좌우 반전처럼 반복되어야하는데 2개씩 자르는데 같으면 0
	for (int i = 2; i <= size; i += 2) {
		if (str.substr(size - i / 2, i / 2) == str.substr(size - i, i / 2))
			return 0;
	}

	return 1;
}

void DFS(int n, string str) {
	//답이 나온경우
	if (flag == 1)
		return;

	//탈출조건
	if (str.length() == n) {
		result = str;
		flag = 1;
		return;
	}

	//1부터 순차적으로 진행하므로
	//처음 나오는 좋은 수열이 가장 작은 값
	for (int i = 1; i <= 3; ++i) {
		str.push_back((char)i + '0');
		//현재 문자열이 좋은 수열이면?
		if (is_Good_seq(str) == 1)
			DFS(n, str); //진행
		str.pop_back();
	}
	return;
}

string solution(int n) {
	string answer;

	flag = 0;
	//백트래킹으로 좋은 수열 구함
	DFS(n, "");

	answer = result;
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	string ret = solution(n);
	cout << ret;

	return 0;
}
