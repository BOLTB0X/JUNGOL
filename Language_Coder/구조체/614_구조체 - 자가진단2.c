#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct INFO {
	char school[21];
	int rank;
} INFO;

int main(void) {
	INFO student = { "Jejuelementary", 6 };
	char tmp1[21];
	int tmp2;
	scanf("%s", tmp1);
	scanf("%d", &tmp2);

	printf("%d grade in %s School\n", student.rank, student.school);

	strcpy(student.school, tmp1);
	student.rank = tmp2;

	printf("%d grade in %s School\n", student.rank, student.school);

	return 0;
}