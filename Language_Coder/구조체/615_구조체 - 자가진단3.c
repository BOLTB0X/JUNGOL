#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct INFO {
	char name[21];
	int kor;
	int eng;
} INFO;

int main(void) {
	INFO student1;
	INFO student2;

	scanf("%s %d %d", student1.name, &student1.kor,&student1.eng);
	scanf("%s %d %d", student2.name, &student2.kor,&student2.eng);

	printf("%s %d %d\n", student1.name, student1.kor, student1.eng);
	printf("%s %d %d\n", student2.name, student2.kor, student2.eng);
	printf("avg %d %d\n",(student1.kor+student2.kor)/2, (student1.eng + student2.eng) / 2);

	return 0;
}