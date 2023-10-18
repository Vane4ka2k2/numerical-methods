#include "Polynomial.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial p({ -3, 1, 1, 0, 1 });
    Polynomial q({ -3, 1, 1, 1 });
    cout << "P: " << p << endl;
    cout << "Q: " << q << endl;
    cout << "НОД(P, Q): " << p.gcd(q) << endl;

    cout << endl;
    Polynomial p1({ 0, 1, 0, -2, 0, 1 });
    cout << "p1: " << p1 << endl;
    cout << "p1': " << p1.derivative() << endl;
    cout << "Многочлен без кратных корней: " << p1.removeMultiplicity() << endl;

    return 0;
}

/* output
P: x^4 + x^2 + x - 3
Q: x^3 + x^2 + x - 3
НОД(P, Q): 27x - 27

p1: x^5 - 2x^3 + x
p1': 5x^4 - 6x^2 + 1
Многочлен без кратных корней: -x^3 + x
*/
