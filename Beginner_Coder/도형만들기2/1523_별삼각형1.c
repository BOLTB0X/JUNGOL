#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

void triangle_type(int h, int t) {
	if (t == 1) {
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= i; ++j) {
				printf("*");
			}
			printf("\n");
		}
	}
	else if (t == 2) {
		for (int i = h; i >= 1; --i) {
			for (int j = 1; j <= i; ++j) {
				printf("*");
			}
			printf("\n");
		}
	}
	
	else if (t == 3) {
		for (int i = h; i >= 1; --i) {
			for (int j = 1; j <= i - 1; ++j) 
				printf(" ");
			for (int j=1;j<2*(h-i+1);++j)
				printf("*");
			printf("\n");
		}
	}
}

void solution(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	if (n <= 100 && m >= 1 && m <= 3) 
		triangle_type(n, m);
			
	else 
		printf("INPUT ERROR!");

	return;
}

int main(void) {
	solution();
	return 0;
}