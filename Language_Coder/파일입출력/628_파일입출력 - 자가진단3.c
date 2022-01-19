#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	char name[20];
	int score;
	int rank;
} INF;


int main(void) {
	INF arr[10];

	for (int i = 0; i < 10; ++i) {
		fscanf(stdin,"%s %d", arr[i].name, &arr[i].score);
		arr[i].rank = 1;
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (arr[i].score < arr[j].score)
				arr[i].rank++;
		}
	}

	printf("Name Score Rank\n");
	for (int i = 0; i < 10; ++i) 
		printf("%4s %5d %4d\n", arr[i].name, arr[i].score, arr[i].rank);

	return 0;
}