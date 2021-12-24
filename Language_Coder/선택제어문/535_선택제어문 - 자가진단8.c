#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double g;

	scanf("%lf", &g);

	switch ((int)g) {
	case 4:
		printf("scholarship\n");
		break;
	case 3:
		printf("next semester\n");
		break;
	case 2:
		printf("seasonal semester\n");
		break;
	default :
		printf("retake\n");
		break;
	}
	return 0;
}