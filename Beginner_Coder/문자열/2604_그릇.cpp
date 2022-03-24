#include <iostream>
#include <string>

using namespace std;

int solution(string bowls) {
	int answer = 10;

	int size = bowls.length();

	for (int i = 1; i < size; ++i) {
		if (bowls[i - 1] == bowls[i])
			answer += 5;
		else
			answer += 10;
	}

	return answer;
}

int main(void) {
	string bowls;
	cin >> bowls;

	int ret = solution(bowls);
	cout << ret;

	return 0;
}
