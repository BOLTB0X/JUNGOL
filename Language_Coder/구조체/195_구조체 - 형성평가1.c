#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct INFO {
	char name[100];
	char number[100];
	char add[100];
} INFO;

void solution(void) {
	INFO inf;

	scanf("%s %s %s", inf.name, inf.number, inf.add);

	printf("name : %s\n", inf.name);
	printf("tel : %s\n", inf.number);
	printf("addr : %s\n", inf.add);
	return;
}

int main(void) {
	solution();
	return 0;
}