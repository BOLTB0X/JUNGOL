#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 

int main() {
	char arr[5][100] = { 0, };
	int i;
	char a[2], b[100];
	int flag = 0;

	for (i = 0; i < 5; i++) {
		scanf("%s", arr[i]);
	}

	scanf("%s %s", a, b);
	for (i = 0; i < 5; i++) {
		if (strstr(arr[i], a) || strstr(arr[i], b)) {
			printf("%s\n", arr[i]); flag++;
		}
	}

	if (flag == 0) 
		printf("none");
	
	return 0;
}