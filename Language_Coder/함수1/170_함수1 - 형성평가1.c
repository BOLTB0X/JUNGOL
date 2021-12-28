#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_call(int dep) {
	if (dep == 0)
		printf("first\n");
	else if (dep == 1)
		printf("second\n");
	else
		printf("third\n");

	for (int i = 0; i < 10; ++i)
		printf("@");
	printf("\n");
	
}

void solution(void) {
	for (int i=0; i<3;++i)
		print_call(i);
	return;
}

int main(void) {
	solution();
	return 0;
}