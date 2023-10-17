#include "Polynomial.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial poly1;
    Polynomial poly2;

    poly1.input();
    poly2.input();

    Polynomial quotient = poly1 / poly2;
    Polynomial remainder = poly1 % poly2;

    cout << "poly1: "; poly1.print(); cout << endl;
    cout << "poly2: "; poly2.print(); cout << endl;
    cout << "quotient: "; quotient.print(); cout << endl;
    cout << "remainder: "; remainder.print(); cout << endl;

    return 0;
}
