#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[100];
	int arr_idx = 0;

	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		
		arr[arr_idx++] = n;

	}
	
	for (int i = arr_idx-1; i >= 0; i--)
		printf("%d ", arr[i]);

	return 0;
}