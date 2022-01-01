#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101];

	scanf("%s",str);

	int len = strlen(str);
	int cnt = len;
	while (cnt--) {
		

		for (int i = len - 1; i > 0; --i) {
			char tmp = str[i];
			str[i] = str[i - 1];
			str[i - 1] = tmp;
		}
	
		printf("%s\n", str);
	}
	return 0;
}