#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char input[101] = {0,};
	int flag = 1;
	fgets(input,101,stdin);
	
	for (int i = 0; input[i] != 0; ++i) {
		if (input[i] == ' ') {
			if (flag == 1) {
				flag = 0;
				printf("\n");
			}
			else
				flag = 1;
		}

		else if (flag == 1)
			printf("%c", input[i]);
	}

	return 0;
}