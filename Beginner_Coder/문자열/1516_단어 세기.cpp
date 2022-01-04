#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void solution(void) {
	string input_words;

	while (1) {
		getline(cin, input_words);
		map<string, int> dic;

		if (input_words == "END")
			break;

		stringstream str_stream(input_words);
		string key;

		while (str_stream >> key) 
			dic[key]++;
		
		for (auto& d : dic)
			cout << d.first << " : " << d.second << '\n';
	}

	return;
}

int main(void) {
	solution();
	return 0;
}