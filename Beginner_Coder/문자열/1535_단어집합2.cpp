#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void solution(vector<string>& str_v) {
	string input;

	while (1) {
		getline(cin, input);

		if (input == "END")
			break;

		stringstream str_stream(input);
		string buffer;

		while (str_stream >> buffer) {
			bool flag = 1;
			for (vector<string>::iterator it = str_v.begin(); it != str_v.end();++it) {
				if (*it == buffer)
					flag = 0;
			}
			if (flag)
				str_v.push_back(buffer);
			
		}
		for (auto& s : str_v)
			cout << s << ' ';
		cout << '\n';
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<string> str_v;

	solution(str_v);

	return 0;
}
