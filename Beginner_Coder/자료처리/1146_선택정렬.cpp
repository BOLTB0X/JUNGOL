#include <iostream>

using namespace std;

void print_arr(int n, int* arr) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
	return;
}

void select_Sort(int n, int* arr) {
	int min_idx;

	for (int i = 0; i < n - 1; ++i) {
		min_idx = i;
		for (int j = i; j < n; ++j) {
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}
		swap(arr[i], arr[min_idx]);
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

	select_Sort(n, arr);
	
	return 0;
}
