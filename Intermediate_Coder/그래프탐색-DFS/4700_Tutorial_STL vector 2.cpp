#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	char cmm;
	vector<int> v;

	cin >> n >> x;
	v.resize(n, x);

	while (1) {
		cin >> cmm;

		if (cmm == 'i') {
			cin >> x;
			v.push_back(x);
		}

		else if (cmm == 'r') {
			if (!v.empty())
				v.pop_back();
		}
		
		else if (cmm == 's') {
			if (v.size() >= 2)
				sort(v.begin(), v.end());
		}

		else if (cmm == 't') {
			if (!v.empty()) {
				int fr = v.front();
				if (v.size() >= 2) {
					int re = v.back();
					v[0] = re;
					v[v.size() - 1] = fr;
				}
			}
		}
		
		else if (cmm == 'e') {
			if (!v.empty()) {
				for (int& a : v)
					cout << a << ' ';
				cout << '\n';
			}
			break;
		}
	}
	return 0;
}