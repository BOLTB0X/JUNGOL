#include <iostream>
#include <string>

using namespace std;

void solution(void) {
	int num1;
	//string num2;
	int num2;
	cin >> num1 >> num2;
	
	//각 자리수와 num1을 곱합
	//for (int i = num2.length()-1; i >= 0; --i)
		//cout << num1 * (num2[i] - '0') << '\n';

	int tmp = num2;
	for (int i = 0; i < 3; ++i) {
		cout << num1 * (tmp % 10) << '\n';
	 	tmp /= 10;
	}

	cout << num1 * num2 << '\n';
	//cout << num1 * stoi(num2) << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
