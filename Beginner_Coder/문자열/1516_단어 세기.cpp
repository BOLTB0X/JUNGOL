#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void solution(void) {
	string input;

	while (1) {
		getline(cin, input);
		map<string, int> dic;

		if (input == "END")
			break;

		stringstream str_stream(input);
		string buffer;

		while (str_stream >> buffer)
			dic[buffer]++;
		for (auto& d : dic)
			cout << d.first << " : " << d.second << '\n';
	}
	return;
}

int main(void) {
	solution();
	return 0;
}
