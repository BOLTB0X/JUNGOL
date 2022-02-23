#include <iostream>
#include <cmath>

using namespace std;

int get_int(int a, int b) {
    return abs(a) > abs(b) ? a : b;
}

float get_float(float a, float b) {
    return fabs(a) < fabs(b) ? a : b;
}

int main(void) {
    int a, b;
    float c, d;
    cin >> a >> b;
    cin >> c >> d;

    cout << get_int(a, b) << '\n';
    printf("%.2lf", get_float(c, d));

    return 0;
}