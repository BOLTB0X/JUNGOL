#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long n;
vector<string> result;
char numbers[3] = { '1','2','3' };

bool is_Good_seq(string seq) {
	int size = seq.length();

	for (int i = 2; i <= size; i += 2) {
		if (seq.substr(size - i / 2, i / 2) == seq.substr(size - i, i / 2))
			return false;
	}
	return true;
}

void DFS(string seq) {
	if (seq.length() == n) {
		result.push_back(seq);
		return;
	}

	//정답이 생기면
	if (!result.empty())
		return;

	//어차피 1부터 3까지 순차적으로 증가하므로
	//0번째 값이 최소값
	for (int i = 0; i < 3; ++i) {
		string tmp = seq + numbers[i];
		if (is_Good_seq(tmp))
			DFS(tmp);
	}
		
	return;
}

void solution(void) {
	DFS("");
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	solution();

	cout << result[0];
	return 0;
}