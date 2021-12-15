#include <iostream>
#include <stack>

using namespace std;

void solution(void) {
	int n;
	stack<int> st;

	cin >> n;
	while (n--) {
		char cmm;
		int value;

		cin >> cmm;

		if (cmm == 'i') {
			cin >> value;
			st.push(value);
		}

		else if (cmm == 'c') 
			cout << st.size() << '\n';
		
		else if (cmm == 'o') {
			if (st.size() == 0)
				cout << "empty" << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
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