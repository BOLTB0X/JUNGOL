#include <iostream>
#include <vector>

using namespace std;

vector<int> combi;
vector<bool> visited;

//중복순열
void per_with_Repet(int n, int level) {
	if (level == n) {
		for (int& c : combi) 
			cout << c << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= 6; ++i) {
		combi.push_back(i);
		per_with_Repet(n, level + 1);
		combi.pop_back();
	}
	return;
}

//중복순열
void com_with_Repet(int n, int level, int cur) {
	if (level == n) {
		for (int& c : combi) 
			cout << c << ' ';
		cout << '\n';
		return;
	}

	for (int i = cur; i <= 6; ++i) {
		combi.push_back(i);
		com_with_Repet(n, level + 1, i);
		combi.pop_back();
	}
	return;
}

//조합
void combination(int n, int level) {
	if (level == n) {
		for (int& c : combi)
			cout << c << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= 6; ++i) {
		if (visited[i])
			continue;
		combi.push_back(i);
		visited[i] = true;
		combination(n, level + 1);
		visited[i] = false;
		combi.pop_back();
	}
	return;
}

void solution(int n, int m) {
	if (m == 1)
		per_with_Repet(n, 0);
	else if (m == 2)
		com_with_Repet(n, 0, 1);
	else if (m == 3) {
		visited.resize(7, false);
		combination(n, 0);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	solution(n, m);
	return 0;
}