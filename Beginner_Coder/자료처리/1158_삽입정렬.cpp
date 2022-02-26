#include <iostream>

using namespace std;

void print_arr(int n, int* arr) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
	return;
}

void insert_Sort(int n, int* arr) {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
		//출력
		print_arr(n, arr);
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int arr[100];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	insert_Sort(n, arr);

	return 0;
}
