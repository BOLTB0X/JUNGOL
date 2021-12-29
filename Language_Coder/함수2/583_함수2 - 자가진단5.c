#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	double n1 = *(double*)a;
	double n2 = *(double*)b;

	if (n1 < n2)
		return -1;
	else if (n1 > n2)
		return 1;
	else
		return 0;
}

void print_answer2(double a, double b, double c) {
    if (a > b) {
        //a가 최대
        if (a > c) {
            printf("%d ", (int)ceil(a));

            if (c > b) {
                printf("%d ", (int)floor(b));
                printf("%d\n", (int)floor(c+0.5));
            }
            else {
                printf("%d ", (int)floor(c));
                printf("%d\n", (int)floor(b + 0.5));
            }

        }
        //c가 최대
        else {
            printf("%d ", (int)ceil(c));
            if (a > b) {
                printf("%d ", (int)floor(b));
                printf("%d\n", (int)floor(a + 0.5));
            }
            else {
                printf("%d ", (int)floor(a));
                printf("%d\n", (int)(int)floor(b + 0.5));
            }
        }
    }

    else {
        //b가 최대
        if (b > c) {
            printf("%d ", (int)ceil(b));

            if (c > a) {
                printf("%d ", (int)floor(a));
                printf("%d\n", (int)floor(c + 0.5));
            }
            else {
                printf("%d ", (int)floor(c));
                printf("%d\n", (int)floor(a + 0.5));
            }

        }
        //c가 최대
        else {
            printf("%d ", (int)ceil(c));
            if (a > b) {
                printf("%d ", (int)floor(b));
                printf("%d\n", (int)floor(a + 0.5));
            }
            else {
                printf("%d ", (int)floor(a));
                printf("%d\n", (int)floor(b + 0.5));
            }
        }
    }
    return;
}

void print_answer(double a, double b, double c) {
	double arr[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;

	qsort(arr, 3, sizeof(double), compare);

	printf("%d %d %d\n", (int)ceil(arr[2]), (int)floor(arr[0]), (int)floor(arr[1]+0.5));
	return;
}

void solution(void) {
	double a, b, c;

	scanf("%lf %lf %lf", &a, &b, &c);
	print_answer2(a, b, c);
	return;
}

int main(void) {
	solution();
	return 0;
}