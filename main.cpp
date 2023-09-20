#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
	Polynomial p1({ -3, 5, -1 });
	Polynomial p2({-3, 0, 0, 1, 0, 1});
	Polynomial p3({0});
	Polynomial p4 = p1 / (-1) + (p2 + p3 * 5) / 3;
	
	cout << "p4: " << p4 << endl;
}