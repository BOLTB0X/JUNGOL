#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int answer1, answer2;
} Pair;

// 최대공약수
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

// 최소공배수
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

Pair solution(int n, int* arr) {
	Pair answer = { 0,0 };

	answer.answer1 = arr[0];
	answer.answer2 = arr[0];

	for (int i = 1; i < n; ++i) {
		answer.answer1 = gcd(answer.answer1, arr[i]);
		answer.answer2 = lcm(answer.answer2, arr[i]);
	}

	return answer;
}

int main(void) {
	int n;
	int arr[10];
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	Pair ret = solution(n, arr);
	printf("%d ",ret.answer1);
	printf("%d",ret.answer2);
	return 0;
}
