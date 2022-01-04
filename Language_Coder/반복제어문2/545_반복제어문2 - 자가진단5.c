#include <stdio.h>

int main(void) {
	int arr[10];
	int a = 0, b = 0;

	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);

		if (arr[i] % 3 == 0)
			a++;
		if (arr[i] % 5 == 0)
			b++;
	}
	

	printf("Multiples of 3 : %d\n", a);
	printf("Multiples of 5 : %d\n", b);
	return 0;
}