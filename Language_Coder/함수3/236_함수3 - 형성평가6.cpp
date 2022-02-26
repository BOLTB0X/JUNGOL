#include <iostream>
#include <string>

using namespace std;

int recursive_func(int number) {
	if (number == 0) 
		return 1;
	
	if (number % 10 == 0) //0ÀÎ °æ¿ì
		return 1 * recursive_func(number / 10);

	else
		return (number % 10) * recursive_func(number / 10);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[3];

	for (int i = 0; i < 3; ++i)
		cin >> arr[i];

	int ret = recursive_func(arr[0] * arr[1] * arr[2]);

	cout << ret;
	return 0;
}