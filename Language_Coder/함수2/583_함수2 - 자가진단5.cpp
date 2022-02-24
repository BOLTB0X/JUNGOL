#include <iostream>
#include <cmath>

using namespace std;

void print_answer2(double a, double b, double c) {
    if (a > b) {
        //a가 최대
        if (a > c) {
            printf("%d ", (int)ceil(a));

            if (c > b) {
                printf("%d ", (int)floor(b));
                printf("%d\n", (int)floor(c + 0.5));
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

void swap(double* a, double* b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void select_Sort(double* arr, int start, int end) {
    for (int i = 0; i < 2; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < 3; ++j) {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(&arr[i], &arr[min_idx]);
    }
    return;
}

void print_answer(double a, double b, double c) {
    double arr[3];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    select_Sort(arr, 0, 3);

    printf("%d %d %d\n", (int)ceil(arr[2]), (int)floor(arr[0]), (int)floor(arr[1] + 0.5));
    return;
}

int main(void) {
	double a, b, c;
	cin >> a >> b >> c;

    print_answer(a, b, c);
	return 0;
}