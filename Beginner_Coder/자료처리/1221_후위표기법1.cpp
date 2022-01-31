#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<char>& v) {
	int answer = 0;
	stack<int> num;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i] >= '0' && v[i] <= '9')
			num.push(v[i] - '0');
		else {
			int num1 = num.top();
			num.pop();
			int num2 = num.top();
			num.pop();

			if (v[i] == '+')
				num.push(num2 + num1);
			else if (v[i] == '-')
				num.push(num2 - num1);
			else if (v[i] == '*')
				num.push(num2 * num1);
			else if (v[i] == '/') 
				num.push(num2 / num1);
		}
	}

	answer = num.top();
	return answer;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	vector<char> v;

	cin >> n;
	v.resize(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ret = solution(n, v);

	cout << ret;
	return 0;
}