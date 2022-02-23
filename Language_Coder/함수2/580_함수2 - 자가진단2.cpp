#include <iostream>

using namespace std;

int months_Check(int m, int d) {
    if (d < 1 || m>12)
        return 0;
    switch (m) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return d <= 31 ? 1 : 0;
    case 2:
        return d <= 29 ? 1 : 0;
    default:
        return d <= 30 ? 1 : 0;
    }
}

int main(void) {
	int m, d;
	cin >> m >> d;

    if (months_Check(m, d))
        printf("OK!\n");
    else
        printf("BAD!\n");
    return 0;
}