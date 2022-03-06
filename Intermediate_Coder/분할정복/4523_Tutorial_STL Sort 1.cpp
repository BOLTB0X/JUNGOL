#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

void print_arr(int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, start, end;
	
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> start >> end;

	//일정 구간만 정렬
	sort(arr + start, arr + end + 1);

	print_arr(n);
	cout << "\n";
	
	sort(arr, arr + n);
	print_arr(n);

	return 0;
}
