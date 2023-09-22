#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	Polynomial p1;
	Polynomial p2;

	p1.input();
	p2.input();

	Polynomial p3 = p1 / p2;

	cout << "p3: " << p3 << endl;

	system("pause");
}