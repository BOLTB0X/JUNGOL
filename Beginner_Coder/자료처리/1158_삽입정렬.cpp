#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n, int* arr) {
	vector<vector<int>> answer;

	// 삽입정렬
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			// 앞에 있는 원소가 크다면
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}

		vector<int> tmp;
		// 단계가 끝나면 배열을 정답 벡터에 삽입
		for (int i = 0; i < n; ++i)
			tmp.push_back(arr[i]);
		answer.push_back(tmp);
	}
	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	vector<vector<int>> ret = solution(n, arr);
	for (int i = 0; i < ret.size(); ++i) {
		for (int& r : ret[i]) 
			cout << r << ' ';
		cout << '\n';
	}

	delete[] arr;
	return 0;
}
