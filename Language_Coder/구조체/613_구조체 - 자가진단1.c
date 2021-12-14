#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct INFO {
	char name[21];
	char school[21];
	int rank;
} INFO;

int main(void) {
	INFO student;

	scanf("%s", student.name);
	scanf("%s", student.school);
	scanf("%d", &student.rank);

	printf("Name : %s\n", student.name);
	printf("School : %s\n", student.school);
	printf("Grade : %d\n", student.rank);

	return 0;
}