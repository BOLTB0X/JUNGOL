#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct INFO{
	char name[10];
	int hight;
	double weight;
} INFO;

void str_Sort(INFO arr[]) {
	INFO tmp[5];
	for (int i = 0; i < 5; ++i) {
		for (int j = i; j < 5; ++j) {
			if (strcmp(arr[i].name, arr[j].name) > 0) {
				INFO tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	return;
}

void s_Sort(INFO arr[]) {
	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			if (arr[i].weight < arr[j].weight) {
				INFO tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	return;
}

void solution(void) {
	INFO student[5];
	for (int i = 0; i < 5; ++i) 
		scanf("%s %d %lf", student[i].name, &student[i].hight, &student[i].weight);
	
	str_Sort(student);

	printf("name\n");
	for (int i = 0; i < 5; ++i)
		printf("%s %d %.1lf\n", student[i].name, student[i].hight, student[i].weight);
	printf("\n");

	s_Sort(student);
	printf("weight\n");
	for (int i = 0; i < 5; ++i)
		printf("%s %d %.1lf\n", student[i].name, student[i].hight, student[i].weight);
	printf("\n");

	return;
}

int main(void) {
	solution();
	return 0;
}