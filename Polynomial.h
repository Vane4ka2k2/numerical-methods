#include <vector>
#include <iostream>
using namespace std;

class Polynomial {
private:
	vector<double> coefficients; // Вектор коэффициентов
public:
	// Конструкторы и деструктор
	Polynomial() {}
	Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {}
	~Polynomial() {}

	// Метод удаления незначащих нулей
	void removeLeadingZeros() {
		while (coefficients.size() > 1 && coefficients.back() == 0) {
			coefficients.pop_back();
		}
	};

	// Метод для округления коэффициентов
	void roundCoefficients() {
		for (size_t i = 0; i < coefficients.size(); ++i) {
			coefficients[i] = round(coefficients[i] * 1000) / 1000;
		}
	};

	// Перегрузка оператора не равно для многочлен != многочлен
	bool operator!=(const Polynomial& other) const {
		return coefficients != other.coefficients;
	};

	// Перегрузка оператора равно для многочлен == многочлен
	bool operator==(const Polynomial& other) const {
		return coefficients == other.coefficients;
	};

	// Перегрузка оператора больще для многочлен > многочлен
	bool operator>(const Polynomial& other) const {
		size_t maxDegree = std::max(coefficients.size(), other.coefficients.size());

		for (size_t i = maxDegree; i > 0; --i) {
			double thisCoeff = (i <= coefficients.size()) ? coefficients[i - 1] : 0;
			double otherCoeff = (i <= other.coefficients.size()) ? other.coefficients[i - 1] : 0;

			if (thisCoeff > otherCoeff) {
				return true;
			}
			else if (thisCoeff < otherCoeff) {
				return false;
			}
		}

		return false; // Если все коэффициенты равны, то многочлены равны
	}

	// Перегрузка оператора сложения для многочлена + многочлен
	Polynomial operator+(const Polynomial& other) const {
		vector<double> result(max(coefficients.size(), other.coefficients.size()));

		for (size_t i = 0; i < coefficients.size(); ++i) {
			result[i] += coefficients[i];
		}

		for (size_t i = 0; i < other.coefficients.size(); ++i) {
			result[i] += other.coefficients[i];
		}

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Перегрузка оператора сложения для многочлена + число
	Polynomial operator+(double scalar) const {
		vector<double> result(coefficients);

		result[0] += scalar;

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Перегрузка оператора вычитания для многочлена - многочлен
	Polynomial operator-(const Polynomial& other) const {
		vector<double> result(max(coefficients.size(), other.coefficients.size()));

		for (size_t i = 0; i < coefficients.size(); ++i) {
			result[i] += coefficients[i];
		}

		for (size_t i = 0; i < other.coefficients.size(); ++i) {
			result[i] -= other.coefficients[i];
		}

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Перегрузка оператора вычитания для многочлена - число
	Polynomial operator-(double scalar) const {
		vector<double> result(coefficients);

		result[0] -= scalar;

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Перегрузка оператора умножения для многочлена * многочлен
	Polynomial operator*(const Polynomial& other) const {
		vector<double> result(coefficients.size() + other.coefficients.size() - 1, 0);

		for (size_t i = 0; i < coefficients.size(); ++i) {
			for (size_t j = 0; j < other.coefficients.size(); ++j) {
				result[i + j] += coefficients[i] * other.coefficients[j];
			}
		}

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Перегрузка оператора умножения для многочлена * число
	Polynomial operator*(double scalar) const {
		vector<double> result(coefficients);

		for (size_t i = 0; i < result.size(); ++i) {
			result[i] *= scalar;
		}

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

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
		Polynomial res(quotient);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Перегрузка оператора деления для многочлена / число
	Polynomial operator/(double scalar) const {
		vector<double> result(coefficients);

		for (size_t i = 0; i < result.size(); ++i) {
			result[i] /= scalar;
		}

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

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

		Polynomial res(dividend);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Взятие производной от многочлена
	Polynomial derivative() const {
		vector<double> result(coefficients.size() - 1, 0);

		for (size_t i = 1; i < coefficients.size(); ++i) {
			result[i - 1] = coefficients[i] * i;
		}

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Нахождение НОД двух многочленов
	Polynomial gcd(const Polynomial& other) const {
		Polynomial dividend = *this;
		Polynomial divisor = other;
		Polynomial quotient = dividend / divisor;
		Polynomial remainder = dividend % divisor;
		Polynomial zero({ 0.0 });

		while (!remainder.coefficients.empty()) {
			dividend = divisor;
			divisor = remainder;
			quotient = dividend / divisor;
			remainder = dividend % divisor;
		}

		return divisor;
	};

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
