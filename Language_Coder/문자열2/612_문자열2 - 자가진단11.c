#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	int nums[5];
	char str[1000001] = { "\0", };

	for (int i = 0; i < 5; ++i)
		scanf("%d", &nums[i]);

	sprintf(str, "%d%d%d%d%d", nums[0], nums[1], nums[2], nums[3], nums[4]);

	for (int i = 0; i < strlen(str); ++i) {
		printf("%c", str[i]);
		if (i % 3 == 2)
			printf("\n");
	}
	return;
}

int main(void) {
	solution();

	return 0;
}