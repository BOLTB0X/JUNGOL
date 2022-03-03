#include <iostream>
#include <string>
#include <vector>

using namespace std;

int flag = 0; //체크용
string result;

//좋은 수열인지 체크
int is_Good_seq(string str) {
	int size = str.length();

	for (int i = 2; i <= size; i += 2) {
		//같으면 안되고
		//뒤집어져 -> 대칭으로 나와야함
		if (str.substr(size - i / 2, i / 2) == str.substr(size - i, i / 2))
			return 0;
	}
	return 1;
}

//DFS로 백트래킹
void DFS(long long n, string seq) {
	//답이 나왔다면
	if (flag == 1)
		return;

	if (seq.length() == n) {
		result = seq;
		flag = 1; //체크
		return;
	}

	//순자적으로 증가하므로
	//탐색 시작
	for (int i = 1; i <= 3; ++i) {
		seq.push_back(char(i + '0'));
		if (is_Good_seq(seq) == 1) //좋은 수열이면
			DFS(n, seq);
		seq.pop_back();
	}
	return;
}

string solution(long long n) {
	string answer;

	DFS(n, "");

	answer = result;
	return answer;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;

	string ret = solution(n);
	cout << ret;
	return 0;
}
