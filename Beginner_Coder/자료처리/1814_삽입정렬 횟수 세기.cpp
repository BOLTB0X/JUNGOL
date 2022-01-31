#include <iostream>

using namespace std;

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void solution(int n, int* arr) {
	int cnt = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
				cnt++;
			}
		}
	}

	cout << cnt;
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