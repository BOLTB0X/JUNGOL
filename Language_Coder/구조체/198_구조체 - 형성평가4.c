#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct INFO {
	int height;
	double weight;
} INFO;

void solution(void) {
	INFO fafa;
	INFO mama;
	INFO answer;

	scanf("%d %lf", &fafa.height, &fafa.weight);
	scanf("%d %lf", &mama.height, &mama.weight);

	answer.height = ((fafa.height + mama.height) / 2) + 5;
	answer.weight = (double)(fafa.weight + mama.weight) / 2 - 4.5;

	printf("height : %dcm\n", answer.height); 
	printf("weight : %.1lfkg\n", answer.weight);
	return;
}

int main(void) {
	solution();
	return 0;
}