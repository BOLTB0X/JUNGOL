#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

struct SQ {
    int y, x;
    bool operator<(SQ s) {
        return y * x < s.y * s.x;
    }
};

int main(void) {
    SQ arr[2];

    scanf("%d %d", &arr[0].y, &arr[0].x);
    scanf("%d %d", &arr[1].y, &arr[1].x);

    if (arr[0] < arr[1])  
        printf("a is smaller\n");
    else      
        printf("b is smaller\n");

    return 0;
}