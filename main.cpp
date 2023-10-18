#include "Polynomial.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial poly1({ -5, 8, -3, -4, 2, 0, 1 });
    Polynomial poly2({ 1, -1, 1, 0, 0, 1 });
    Polynomial poly3 = poly1.gcd(poly2);

    cout << "poly1: "; poly1.print(); cout << endl;
    cout << "poly2: "; poly2.print(); cout << endl;
    cout << "poly3: "; poly3.print(); cout << endl;

    return 0;
}
