#include <iostream>

using namespace std;

int arr[20001];

int is_Same(int n, int* r_arr) {
	for (int i = 1; i <= n; ++i) {
		if (arr[i] != r_arr[i])
			return 0;
	}

	return 1;
}

void arr_Shuffle(int n, int* r_arr) {
	for (int i = 1; i <= n - 2; ++i) {
		if (i == 2)
			continue;
		swap(r_arr[i], r_arr[i + 2]);
	}

	return;
}

long long solution(int n) {
	int answer = 0;

	long long cnt = 1;
	int* ran_arr = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		ran_arr[i] = arr[i];

	arr_Shuffle(n, ran_arr);

	while (1) {
		if (is_Same(n, ran_arr) == 1)
			break;
		arr_Shuffle(n, ran_arr);
		cnt++;
	}

	answer = cnt;
	delete[] ran_arr;
	return answer;
}

int main(void) {
	// 1 2 3 4 5 6
	// 3 2 1 4 5 6
	// 3 2 5 4 1 6
	// 3 2 5 6 1 4
	// 2�� ������
	// 5 2 3 6 1 4
	// 5 2 1 6 3 4
	// 5 2 1 4 3 6
	// 1 -> 3 , 2�� ��ŵ, 3->5, 4->6 
	// ���̰� n�̸� n - 2����

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) 
		cin >> arr[i];
	
	long long ret = solution(n);
	cout << ret;
	return 0;
}
