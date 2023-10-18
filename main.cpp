#include "Polynomial.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial p1({ 0, 1, 0, -2, 0, 1 });
    Polynomial derp1 = p1.derivative();
    Polynomial p2 = p1.gcd(derp1);
    Polynomial p3 = p1.removeMultiplicity();

    cout << "p1: " << p1 << endl;
    cout << "p1': " << derp1 << endl;
    cout << "нод p1 и p1': " << p2 << endl;
    cout << "p1 без кратных корней: " << p3 << endl;

    return 0;
}
