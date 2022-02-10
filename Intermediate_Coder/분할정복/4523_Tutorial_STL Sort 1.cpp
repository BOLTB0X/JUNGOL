#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, start, end;
	
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> start >> end;

	
	sort(arr + start, arr + end + 1);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	cout << "\n";
	
	sort(arr, arr + n);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
	return 0;
}