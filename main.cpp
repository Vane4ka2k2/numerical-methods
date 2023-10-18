#include "Polynomial.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial p1({ 2, 3, 3, 1 });
    Polynomial p2({ 1, 2, 2, 1 });
    Polynomial p3 = p1.gcd(p2);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "НОД p1 и p2: " << p3 << endl;
    cout << endl;
    Polynomial p4({ 0, 1, 0, -2, 0, 1 });
    Polynomial p5 = p4.derivative();
    Polynomial p6 = p4.gcd(p5);
    cout << "p4: " << p4 << endl;
    cout << "p4': " << p5 << endl;
    cout << "НОД p4 и p4': " << p6 << endl;

    return 0;
}

//output
/*p1: x ^ 3 + 3x ^ 2 + 3x + 2
p2 : x ^ 3 + 2x ^ 2 + 2x + 1
НОД p1 и p2 : x ^ 2 + x + 1

p4 : x ^ 5 - 2x ^ 3 + x
p4': 5x^4 - 6x^2 + 1
НОД p4 и p4': -x^2 + 1*/
