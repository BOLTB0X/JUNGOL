#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct INFO {
	int x1, y1, x2, y2;
} INFO;

void solution(void) {
	INFO point1;
	INFO point2;
	INFO answer;

	scanf("%d %d %d %d", &point1.x1, &point1.y1, &point1.x2, &point1.y2);
	scanf("%d %d %d %d", &point2.x1, &point2.y1, &point2.x2, &point2.y2);
	
	
	if (point1.x1 < point2.x1)
		answer.x1 = point1.x1;
	else
		answer.x1 = point2.x1;
	
	if (point1.y1 < point2.y1)
		answer.y1 = point1.y1;
	else
		answer.y1 = point2.y1;
	
	if (point1.x2 < point2.x2)
		answer.x2 = point2.x2;
	else
		answer.x2 = point1.x2;
	
	if (point1.y2 < point2.y2)
		answer.y2 = point2.y2;
	else
		answer.y2 = point1.y2;

	printf("%d %d %d %d\n",answer.x1, answer.y1, answer.x2, answer.y2);
	return;
}

int main(void) {
	solution();
	return 0;
}