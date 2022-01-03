#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void solution(void) {
	vector<string> words_list;
	string input_word;

	while (1) {
		getline(cin, input_word);

		if (input_word == "END")
			break;

		stringstream str_stream(input_word);
		string buffer;

		while (str_stream >> buffer) {
			bool isMatch = true;
			for (vector<string>::iterator it = words_list.begin(); it != words_list.end(); ++it) {
				if (*it == buffer)
					isMatch = false;
			}
			if (isMatch)
				words_list.push_back(buffer);
		}
		
		for (int i = 0; i < words_list.size(); ++i) 
			cout << words_list[i] << ' ';
		cout << "\n";
		
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}