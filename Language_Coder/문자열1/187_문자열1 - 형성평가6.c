#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101] = { '\0', };
	scanf("%s", str);
	int len = strlen(str);

	while (strlen(str) > 1) {
		char tmp[101] = { "\0", };
		int idx;
		scanf("%d", &idx);

		if (idx > strlen(str))
			str[strlen(str) - 1] = '\0';
		else {
			for (int i = 0; i < len; ++i) {
				if (i == idx - 1)
					continue;
				tmp[i] = str[i];
			}
		}

		strcpy(str, tmp);

		printf("%s\n", str);
	}

	return 0;
}