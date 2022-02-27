#include <iostream>
#include <cmath>

using namespace std;

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void bubble_Sort(int* arr) {
    for (int i = 6; i >= 4; --i) {
        for (int j = 0; j < 6; ++j) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
        
    }
    return;
}

int main(void) {
    int arr[7];
    for (int i = 0; i < 7; ++i)
        cin >> arr[i];

    bubble_Sort(arr);
    for (int i = 0; i < 7; ++i)
        cout << arr[i] << ' ';

    return 0;
}
