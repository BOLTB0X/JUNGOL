#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;
vector<int> visited(7 ,0);

void dice1(int n, int level) {
	if (level == n) {
		for (int i = 0; i < numbers.size(); ++i)
			cout << numbers[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= 6; ++i) {
		numbers.push_back(i);
		dice1(n, level + 1);
		numbers.pop_back();
	}

	return;
}

void dice2(int n, int cur, int level) {
	if (level == n) {
		for (int i = 0; i < numbers.size(); ++i)
			cout << numbers[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = cur; i <= 6; ++i) {
		numbers.push_back(i);
		dice2(n, i, level + 1);
		numbers.pop_back();
	}

	return;
}

void dice3(int n, int level) {
	if (level == n) {
		for (int i = 0; i < numbers.size(); ++i)
			cout << numbers[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= 6; ++i) {
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		numbers.push_back(i);
		dice3(n, level + 1);
		numbers.pop_back();
		visited[i] = 0;
	}

	return;
}

int main(void) {
	int n, m;

	cin >> n >> m;
	
	if (m == 1)
		dice1(n, 0); // 중복 순열

	else if (m == 2)
		dice2(n, 1, 0); // 중복 조합
	else 
		dice3(n, 0); // 순열
	
	return 0;
}
