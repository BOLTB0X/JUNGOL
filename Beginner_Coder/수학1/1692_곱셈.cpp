#include <iostream>
#include <string>

using namespace std;

void solution(void) {
	int num1;
	string num2;

	cin >> num1 >> num2;
	
	for (int i = num2.length()-1; i >= 0; --i)
		cout << num1 * (num2[i] - '0') << '\n';
	cout << num1 * stoi(num2) << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}