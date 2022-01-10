#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[5];
	
	int succes_cnt = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 4; ++j) {
			scanf("%d", &arr[j]);
		}
		int tot = 0;
		for (int j = 0; j < 4; ++j) {
			tot += arr[j];
		}

		if ((double)tot / 4 >= 80) {
			printf("pass\n"); 
			succes_cnt++;
		}
		else
			printf("fail\n");
	}
	printf("Successful : %d\n", succes_cnt);

	return;
}