#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct INFO {
	int x;
	int y;
} INFO;

int main(void) {
	INFO point1;
	INFO point2;
	INFO point3;

	scanf("%d %d %d %d %d %d", &point1.x, &point1.y, &point2.x, &point2.y, &point3.x, &point3.y);
	
	printf("(%.1lf, %.1lf)\n", (double)(point1.x + point2.x + point3.x) / 3, (double)(point1.y + point2.y + point3.y) / 3);

	return 0;
}