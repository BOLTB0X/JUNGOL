#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101] = { '\0', };
	
	scanf("%s", str);

	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] >= 65 && str[i] <= 90)
			printf("%c", str[i] + 32);
		else if (str[i] >= 97 && str[i] <= 122)
			printf("%c", str[i]);
		else if (str[i] >= 48 && str[i] <= 57)
			printf("%c", str[i]);
		
	}
	return 0;
}