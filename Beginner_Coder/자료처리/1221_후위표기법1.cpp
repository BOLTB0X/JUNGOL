#include <iostream>
#include <vector>

using namespace std;

int stack[101];
int top = -1;

// 푸쉬
void push(int data) {
	stack[++top] = data;
	return;
}

// 팝
int pop(void) {
	return stack[top--];
}

int solution(int n, vector<char>& arr) {
	int answer = 0;

	for (char& a : arr) {
		// 정수를 입력 받으면
		if (a >= '0' && a <= '9')
			push(a - '0');

		else {
			int number = pop();
			if (a == '+')
				stack[top] += number;
			
			else if (a == '-')
				stack[top] -= number;

			else if (a == '*')
				stack[top] *= number;

			else if (a == '/')
				stack[top] /= number;
		}
	}

	answer = pop(); // 최상단
	return answer;
}

int main(void) {
	int n;
	vector<char> arr;
	
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int ret = solution(n, arr);
	cout << ret;
	return 0;
}
