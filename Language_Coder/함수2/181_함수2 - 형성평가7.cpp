#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    double r, radian = 3.141592;
    
    cout << "radius : ";
    cin >> r;
    printf("area = %.3lf", r * r * radian);

    return 0;
}