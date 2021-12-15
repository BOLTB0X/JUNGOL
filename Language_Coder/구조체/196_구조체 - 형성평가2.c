#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct INFO {
	char name[100];
	char number[100];
	char add[100];
} INFO;

void str_Sort(INFO arr[]) {
	for (int i = 0; i < 2; ++i) {
		for (int j = i+1; j < 3; ++j) {
			if (strcmp(arr[i].name, arr[j].name) > 0) {
				INFO tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	return;
}

void solution(void) {
	INFO person[3];
	for (int i=0; i<3;++i) 
		scanf("%s %s %s", person[i].name, person[i].number, person[i].add);

	str_Sort(person);

	printf("name : %s\n", person[0].name);
	printf("tel : %s\n", person[0].number);
	printf("addr : %s\n", person[0].add);
	return;
}

int main(void) {
	solution();
	return 0;
}