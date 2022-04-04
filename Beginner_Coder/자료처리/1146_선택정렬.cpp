#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, int* arr) {
	vector<vector<int>> answer;
	int min_idx = 0;

	// 선택정렬
	for (int i = 0; i < n - 1; ++i) {
		min_idx = i;
		vector<int> tmp;
		for (int j = i; j < n; ++j) {
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}
		swap(arr[min_idx], arr[i]);
		for (int i = 0; i < n; ++i)
			tmp.push_back(arr[i]);
		answer.push_back(tmp);
	}
	return answer;
}

int main(void) {
	int n;
	int arr[100];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	vector<vector<int>> ret = solution(n, arr);
	for (vector<int>& r : ret) {
		for (int i = 0; i < r.size(); ++i)
			cout << r[i] << ' ';
		cout << '\n';
	}
	
	return 0;
}
