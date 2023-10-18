#include "Polynomial.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial p1({ 0, 1, 0, -2, 0, 1 });
    Polynomial der_p1 = p1.derivative();
    Polynomial p2 = p1.gcd(der_p1);
    Polynomial p3 = p1.removeMultiplicity();

    cout << "p1: " << p1 << endl;
    cout << "p1': " << der_p1 << endl;
    cout << "НОД p1 и p1': " << p2 << endl;
    cout << "p1 без кратных корней: " << p3 << endl;

    return 0;
}
