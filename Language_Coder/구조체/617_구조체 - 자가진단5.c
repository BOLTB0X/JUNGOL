#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct INFO {
	char name[21];
	int hight;
} INFO;

int main(void) {
	INFO* arr = malloc(sizeof(INFO) * 5);
	int min_idx = 0;
	int min_hight = 0x7fffffff;

	for (int i = 0; i < 5; ++i) {
		scanf("%s %d", arr[i].name, &arr[i].hight);

		if (min_hight > arr[i].hight) {
			min_hight = arr[i].hight;
			min_idx = i;
		}
	}

	printf("%s %d\n", arr[min_idx].name, arr[min_idx].hight);

	return 0;
}