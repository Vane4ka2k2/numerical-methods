#include "Polynomial.h"
#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	Polynomial p1({ 1, -1, 1, 0, 2, 3 });
	Polynomial p2({ 0, 1, 2, 1 });

	cout << "p1: "; p1.print(); cout << ". ";
	cout << "Многочлен p1 имеет степень: " << p1.getDegree() << endl;
	cout << "p2: "; p2.print(); cout << ". ";
	cout << "Многочлен p2 имеет степень: " << p2.getDegree() << endl;
	Polynomial p3 = p1 / p2;
	cout << "p3 = p1 / p2: "; p3.print(); cout << ". ";
	cout << "Многочлен p3 имеет степень: " << p3.getDegree() << endl << endl;

	Polynomial p4 = p1.derivative();
	cout << "p4 = p1': "; p4.print(); cout << endl;
	cout << "Многочлен p1 имеет степень: " << p1.getDegree() << endl;
	cout << "Многочлен p4 имеет степень: " << p4.getDegree() << endl << endl;
	cout << "p1: "; p1.print(); cout << endl;
	Polynomial p5 = p1 / p4;
	cout << "p5: "; p5.print(); cout << endl;

	cout << endl;
	cout << "p1: "; p1.print(); cout << ". ";
	cout << "Многочлен p1 имеет степень: " << p1.getDegree() << endl;
	cout << "p2: "; p2.print(); cout << ". ";
	cout << "Многочлен p2 имеет степень: " << p2.getDegree() << endl;
	cout << "p3: "; p3.print(); cout << ". ";
	cout << "Многочлен p3 имеет степень: " << p3.getDegree() << endl;
	cout << "p4: "; p4.print(); cout << ". ";
	cout << "Многочлен p4 имеет степень: " << p4.getDegree() << endl;
	cout << "p5: "; p5.print(); cout << ". ";
	cout << "Многочлен p5 имеет степень: " << p5.getDegree() << endl;

	return 0;
}
