#include <iostream>

using namespace std;

int insert_Sort(int n, int* arr) {
	int cnt = 0;
	
	// 삽입정렬 실행
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				cnt++;
			}
		}
	}

	return cnt; //반환
}

int main(void) {
	int n;
	int* arr;

	cin >> n;
	arr = (int*)new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = insert_Sort(n, arr);
	cout << ret;

	delete(arr);
	return 0;
}
