#include <iostream>
#include <cmath>

using namespace std;

void printNum(int a) {
    cout << a << endl;
}

void calcCircleArea() {
    const double pi = 3.1416;
    double radius;
    cin >> radius;

    double area = pi * pow(radius, 2);

    cout << area << endl;
}

int main() {
    
    double a = 0.1;
    double b = 102.4;
    for (int i=0;i<10;i++) {
        a += a;
    }

    cout << a << endl;
    cout << b << endl;

    cout << a-b << endl;

    return 0;
}