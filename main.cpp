#include "Polynomial.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial poly1({ 0, 1, 0, -2, 0, 1 });
    Polynomial poly2 = poly1.derivative();
    Polynomial poly3 = poly1.gcd(poly2);
    Polynomial poly4 = poly1.removeMultiplicity();

    cout << "poly1: " << poly1 << endl;
    cout << "poly2: " << poly2 << endl;
    cout << "poly3: " << poly3 << endl;
    cout << "poly4: " << poly4 << endl;

    return 0;
}
