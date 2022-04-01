#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// 스와핑
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

// 최대공약수
int gcd(int a, int b) {
	if (a < b)
		swap(&a, &b);

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

int main(void) {
	int number1, number2;

	scanf("%d %d", &number1, &number2);
	
	printf("%d\n", gcd(number1, number2));
	printf("%d\n", lcm(number1, number2));

	return 0;
}
