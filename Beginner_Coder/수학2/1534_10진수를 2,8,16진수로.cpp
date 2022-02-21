#include <iostream>
#include <string>

using namespace std;

string solution(int dec, int type) {
	string answer = "", tmp = "";

	while (dec > 0) {
		int r = dec % type;

		if (r > 9)
			tmp += (r - 10 + 'A');
		else
			tmp += (r + '0');
		dec /= type;
	}

	for (int i = tmp.length() - 1; i >= 0; --i)
		answer += tmp[i];
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int dec, type;
	cin >> dec >> type;

	string ret = solution(dec, type);
	cout << ret;
	return 0;
}