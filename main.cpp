#include "Polynomial.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Polynomial p1({ -3, 4, 0, 1 });
    double result = p1.methodNewton();

    cout << "p: " << p1 << endl;
    cout << "Корень: " << result << endl;

    return 0;
}
