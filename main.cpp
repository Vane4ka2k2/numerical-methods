#include "Polynomial.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial poly1({ 0, 1, 0, -2, 0, 1 });
    Polynomial poly2({ 1, 0, -6, 0, 5 });
    Polynomial poly3 = poly1.gcd(poly2);
    Polynomial poly4 = poly1 / poly3;
    Polynomial poly5 = poly2 / poly3;
    Polynomial poly6 = poly1 % poly3;
    Polynomial poly7 = poly2 % poly3;

    cout << "poly1: "; poly1.print(); cout << endl;
    cout << "poly2: "; poly2.print(); cout << endl;
    cout << "poly3: "; poly3.print(); cout << endl;
    cout << "poly4: "; poly4.print(); cout << endl;
    cout << "poly5: "; poly5.print(); cout << endl;
    cout << "poly6: "; poly6.print(); cout << endl;
    cout << "poly7: "; poly7.print(); cout << endl;

    return 0;
}
