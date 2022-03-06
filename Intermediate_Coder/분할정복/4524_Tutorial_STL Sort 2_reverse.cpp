#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[100000];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    //reverse ÀÌ¿כ
    sort(arr, arr + n);
    reverse(arr, arr + n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}