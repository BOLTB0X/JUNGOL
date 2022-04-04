#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int number1, int number2) {
	vector<int> answer;
	
	/*
	// 문자열로 푼다면?
	string s1 = to_string(number1);
	string s2 = to_string(number2);
	for (int i = 2; i >= 0; --i) {
		int tmp = stoi(s1) * (s2[i] - '0');
		answer.push_back(tmp);
	}
	answer.push_back(stoi(s1) * stoi(s2));
	*/

	int n2 = number2;
	for (int i = 0; i < 3; ++i) {
		int tmp = number1 * (n2 % 10);
		answer.push_back(tmp);
		n2 /= 10;
	}

	answer.push_back(number1 * number2);
	return answer;
}

int main(void) {
	int number1, number2;

	cin >> number1 >> number2;
	vector<int> ret = solution(number1, number2);
	for (int& r : ret) 
		cout << r << '\n';
	
	return 0;
}