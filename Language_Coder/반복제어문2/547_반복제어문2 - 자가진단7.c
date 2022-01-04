#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	
	for (int i = 2; i < 7; ++i) {
		int num = i;
		for (int j = 0; j < 5; ++j) 
			printf("%d ", num++);
		printf("\n");
	}

	
	return 0;
}