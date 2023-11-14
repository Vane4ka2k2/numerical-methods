#include "Polynomial.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    /*Polynomial p1({ -3, 4, 0, 1 });
    double result1 = p1.methodNewton(0, 1);

    cout << "p: " << p1 << endl;
    cout << "Корень: " << result1 << endl;*/

    Polynomial p2({ 1, -24, 3, 1 });
    double result1 = p2.methodChordsAndTangents(-7, -6);
    double result2 = p2.methodChordsAndTangents(3, 4);

    cout << "p2: " << p2 << endl;
    cout << "Корень: " << result1 << endl;
    cout << "Корень: " << result2 << endl;

    return 0;
}
