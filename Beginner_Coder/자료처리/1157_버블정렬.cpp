#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void print_arr(int n, int* arr) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
	return;
}

void solution(int n, int* arr) {
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
		print_arr(n, arr);
	}

	return;
}

int main(void) {
	int n;
	int* arr;

	cin >> n;
	arr = (int*)new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	solution(n, arr);
	delete(arr);
	return 0;
}