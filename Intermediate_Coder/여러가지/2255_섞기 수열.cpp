#include <iostream>
#include <cstring>

using namespace std;

int arr[20001];
int pivot[20001];

// �ִ�����
int gcd(int a, int b) {
	if (a < b)
		swap(a, b);

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

// �ּҰ����
long long lcm(long long a, int b) {
	return a * b / gcd(a, b);
}

int get_cycle(int start) {
	int cycle = 1;
	int next = arr[start];

	while (1) {
		// ó�� �ε����� ���ƿ���
		if (start == next)
			return cycle;

		pivot[next] = 1;
		next = arr[next];
		cycle++;
	}
}

long long solution(int n) {
	long long answer = 1;
	memset(pivot, 0, 20001); // �ʱ�ȭ

	for (int i = 1; i <= n; ++i) {
		if (pivot[i] == 1)
			continue;
		answer = lcm(answer, get_cycle(i));
	}
	return answer;
}

int main(void) {
	// 6 -> 3 2 5 6 1 4
	// 1: 3 (1 -> 3 -> 5 -> 1)
	// 2: 1 (2 -> 2)
	// 3: 3 (3 -> 5 -> 1 -> 3)
	// 4: 2 (4 -> 6 -> 4)
	// 5: 3 (5 -> 1 -> 3 -> 5)
	// 2: 2 (4-> 6 -> 4)

	// 3,1 3, 2, 3, 2 �ּҰ����
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	long long ret = solution(n);
	cout << ret;
	return 0;
}
