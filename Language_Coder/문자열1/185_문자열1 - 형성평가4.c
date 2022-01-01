#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101] = { '\0', };
	char target;
	scanf("%s", str);
	scanf(" %c", &target);
	
	int flag = 0;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == target) {
			printf("%d\n", i);
			flag = 1;
			break;
		}
	}
	if (!flag)
		printf("No");
	return 0;
}