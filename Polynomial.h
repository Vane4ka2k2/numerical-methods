#include <vector>
#include <iostream>
using namespace std;

class Polynomial {
private:
	vector<double> coefficients; //вектор коэффициентов
public:
	//конструкторы и деструктор
	Polynomial() {}
	Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {}
	~Polynomial() {}

	// Перегрузка оператора сложения для многочлена + многочлен
	Polynomial operator+(const Polynomial& other) const {
		vector<double> result(max(coefficients.size(), other.coefficients.size()));

		for (size_t i = 0; i < coefficients.size(); ++i) {
			result[i] += coefficients[i];
		}

		for (size_t i = 0; i < other.coefficients.size(); ++i) {
			result[i] += other.coefficients[i];
		}

		return Polynomial(result);
	}

	// Перегрузка оператора сложения для многочлена + числа
	Polynomial operator+(double scalar) const {
		vector<double> result(coefficients);

		result[0] += scalar;

		return Polynomial(result);
	}

	// Перегрузка оператора вычитания для многочлена - многочлен
	Polynomial operator-(const Polynomial& other) const {
		vector<double> result(max(coefficients.size(), other.coefficients.size()));

		for (size_t i = 0; i < coefficients.size(); ++i) {
			result[i] += coefficients[i];
		}

		for (size_t i = 0; i < other.coefficients.size(); ++i) {
			result[i] -= other.coefficients[i];
		}

		return Polynomial(result);
	}

	// Перегрузка оператора вычитания для многочлена - числа
	Polynomial operator-(double scalar) const {
		vector<double> result(coefficients);

		result[0] -= scalar;

		return Polynomial(result);
	}

	// Перегрузка оператора умножения для многочлена * многочлен
	Polynomial operator*(const Polynomial& other) const {
		vector<double> result(coefficients.size() + other.coefficients.size() - 1, 0);

		for (size_t i = 0; i < coefficients.size(); ++i) {
			for (size_t j = 0; j < other.coefficients.size(); ++j) {
				result[i + j] += coefficients[i] * other.coefficients[j];
			}
		}

		return Polynomial(result);
	}

	// Перегрузка оператора умножения для многочлена * числа
	Polynomial operator*(double scalar) const {
		vector<double> result(coefficients);

		for (size_t i = 0; i < result.size(); ++i) {
			result[i] *= scalar;
		}

		return Polynomial(result);
	}

	// Перегрузка оператора деления для многочлена / многочлен
	Polynomial operator/(const Polynomial& other) const {
		vector<double> dividend(coefficients);
		vector<double> quotient;

		while (dividend.size() >= other.coefficients.size()) {
			double factor = dividend.back() / other.coefficients.back();
			quotient.push_back(factor);

			for (size_t i = 0; i < other.coefficients.size(); ++i) {
				dividend[dividend.size() - i - 1] -= factor * other.coefficients[other.coefficients.size() - i - 1];
			}

			while (!dividend.empty() && dividend.back() == 0) {
				dividend.pop_back();
			}
		}

		reverse(quotient.begin(), quotient.end());
		return Polynomial(quotient);
	}

	// Перегрузка оператора деления для многочлена / числа
	Polynomial operator/(double scalar) const {
		vector<double> result(coefficients);

		for (size_t i = 0; i < result.size(); ++i) {
			result[i] /= scalar;
		}

		return Polynomial(result);
	}

	// Перегрузка оператора остатка для многочлена / многочлен
	Polynomial operator%(const Polynomial& other) const {
		vector<double> dividend(coefficients);

		while (dividend.size() >= other.coefficients.size()) {
			double factor = dividend.back() / other.coefficients.back();

			for (size_t i = 0; i < other.coefficients.size(); ++i) {
				dividend[dividend.size() - i - 1] -= factor * other.coefficients[other.coefficients.size() - i - 1];
			}

			while (!dividend.empty() && dividend.back() == 0) {
				dividend.pop_back();
			}
		}

		return Polynomial(dividend);
	}

	//ввод многочлена с клавиатуры
	void input() {
		int degree = 0;
		cout << "Введите степень многочлена: ";
		cin >> degree;

		coefficients.resize(degree + 1);

		for (int i = degree; i >= 0; i--) {
			cout << "Введите коэффициент при x^" << i << ": ";
			cin >> coefficients[i];
		}
	}

	// Вывод многочлена на экран
	void print() const {
		bool isFirstTerm = true;

		for (int i = coefficients.size() - 1; i >= 0; i--) {
			if (coefficients[i] != 0.0) {
				if (!isFirstTerm) {
					if (coefficients[i] > 0) {
						cout << " + ";
					}
					else {
						cout << " - ";
					}
				}
				else {
					isFirstTerm = false;
					if (coefficients[i] < 0) {
						cout << "-";
					}
				}
				double absCoefficient = abs(coefficients[i]);
				if (i == 0 || absCoefficient != 1.0) {
					cout << absCoefficient;
				}
				if (i > 0) {
					cout << "x";
					if (i > 1) {
						cout << "^" << i;
					}
				}
			}
		}
		if (isFirstTerm) {
			cout << "0";
		}
	}
};
