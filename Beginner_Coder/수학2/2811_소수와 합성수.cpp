#include <iostream>
#define ML 1000000001

using namespace std;

void check_Number(int number) {
	if (number == 0 || number == 1) {
		cout << "number one\n";
		return;
	}

	for (long long i = 2; i * i <= number; ++i) {
		if (number % i == 0) {
			cout << "composite number\n";
			return;
		}
	}
			
	cout << "prime number\n";
	return;
}

void solution(int* arr) {
	for (int i = 0; i < 5; ++i) 
		check_Number(arr[i]);
		
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[5] = { 0, };
	for (int i = 0; i < 5; ++i)
		cin >> arr[i];

	solution(arr);
	return 0;
}
