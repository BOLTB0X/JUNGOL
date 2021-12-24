#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int height, weight;
	scanf("%d %d", &height, &weight);

	int flag = weight + 100 - height;
	printf("%d\n", flag);
	if (flag > 0)
		printf("Obesity\n");

	return 0;
}