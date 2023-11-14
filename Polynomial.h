#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
	vector<double> coefficients; // Вектор коэффициентов
public:
	// Конструктор без параметров
	Polynomial() {}
	
	// Конструктор с параметром
	// input:
	//	vector<double> - вектор коэффициентов
	Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {}
	
	// Деструктор без параметров
	~Polynomial() {}

	// Метод удаления незначащих нулей
	// Удаляет незначащие нули из конца вектора
	void removeLeadingZeros() {
		while (coefficients.size() > 1 && coefficients.back() == 0) {
			coefficients.pop_back();
		}
	};

	// Метод для округления коэффициентов
	// Округляет все числа до 3-ёх знаков после запятой
	void roundCoefficients() {
		for (size_t i = 0; i < coefficients.size(); ++i) {
			coefficients[i] = round(coefficients[i] * 1000) / 1000;
		}
	};

	// Перегрузка оператора не равно для многочлен != многочлен
	// input:
	//	Polynomial - Второй многолен
	// output:
	//	true или false
	bool operator!=(const Polynomial& other) const {
		return coefficients != other.coefficients;
	};

	// Перегрузка оператора равно для многочлен == многочлен
	// input:
	//	Polynomial - Второй многолен
	// output:
	//	true или false
	bool operator==(const Polynomial& other) const {
		return coefficients == other.coefficients;
	};

	// Перегрузка оператора больще для многочлен > многочлен
	// input:
	//	Polynomial - Второй многолен
	// output:
	//	true или false
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
	// input:
	//	Polynomial - Второй многолен
	// output:
	//	Polynomial - Результат сложения
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
	// input:
	//	double - число
	// output:
	//	Polynomial - Результат сложения
	Polynomial operator+(const double& scalar) const {
		vector<double> result(coefficients);

		result[0] += scalar;

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Перегрузка оператора вычитания для многочлена - многочлен
	// input:
	//	Polynomial - Второй многочлен
	// output:
	//	Polynomial - Результат вычитания
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
	// input:
	//	double - число
	// output:
	//	Polynomial - Результат вычитания
	Polynomial operator-(const double& scalar) const {
		vector<double> result(coefficients);

		result[0] -= scalar;

		Polynomial res(result);
		res.roundCoefficients();
		res.removeLeadingZeros();
		return res;
	};

	// Перегрузка оператора умножения для многочлена * многочлен
	// input:
	//	Polynomial - Второй многочлен
	// output:
	//	Polynomial - Результат умножения
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
	// input:
	//	double - число
	// output:
	//	Polynomial - Результат умножения
	Polynomial operator*(const double& scalar) const {
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
	// input:
	//	Polynomial - Второй многочлен
	// output:
	//	Polynomial - Результат деления
	Polynomial operator/(const Polynomial& other) const {
		vector<double> dividend(coefficients);
		vector<double> quotient((dividend.size() - 1) - (other.coefficients.size() - 1) + 1, 0);

		while (dividend.size() >= other.coefficients.size()) {
			double factor = dividend.back() / other.coefficients.back();
			quotient[(dividend.size() - 1) - (other.coefficients.size() - 1)] = factor;

			for (size_t i = 0; i < other.coefficients.size(); ++i) {
				dividend[dividend.size() - i - 1] -= factor * other.coefficients[other.coefficients.size() - i - 1];
			}

			while (!dividend.empty() && dividend.back() == 0) {
				dividend.pop_back();
			}
		}

		Polynomial res(quotient);
		res.roundCoefficients();
		return res;
	};

	// Перегрузка оператора деления для многочлена / число
	// input:
	//	double - число
	// output:
	//	Polynomial - Результат деления (целая часть)
	Polynomial operator/(const double& scalar) const {
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
	// input:
	//	Polynomial - ВТорой многочлен
	// output:
	//	Polynomial - Результат деления (остаток)
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
	// output:
	//	Polynomial - производная многочлена
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
	// input:
	//	Polynomial - Второй многочлен
	// output:
	//	Polynomial - Наибольший общий делитель
	Polynomial gcd(const Polynomial& other) const {
		Polynomial dividend = *this;
		Polynomial divisor = other;
		Polynomial quotient = dividend / divisor;
		Polynomial remainder = dividend % divisor;

		while (!remainder.coefficients.empty()) {
			dividend = divisor;
			divisor = remainder;
			quotient = dividend / divisor;
			remainder = dividend % divisor;
		}

		return divisor;
	};

	// Устранение кратности корней многочлена
	// output:
	//	Polynomial - Многочлен без кратных корней
	Polynomial removeMultiplicity() const {
		Polynomial dividend = *this;
		Polynomial divisor = this->derivative();
		Polynomial quotient = dividend / divisor;
		Polynomial remainder = dividend % divisor;

		while (!remainder.coefficients.empty()) {
			dividend = divisor;
			divisor = remainder;
			quotient = dividend / divisor;
			remainder = dividend % divisor;
		}

		return *this / divisor;
	};

	// Вычисление значения многочлена в точке
	// input:
	//	double - Точка
	// output:
	//	double - Значение многочлена в переданной точке
	double rootCalculation(const double& scalar) const {
		double result = coefficients[0];

		for (int i = 1; i < coefficients.size(); i++) {
			result += coefficients[i] * pow(scalar, i);
		}

		return result;
	}

	// Метод Ньютона
	// input:
	//	leftValue - левая граница отрезка
	//	rightValue - правая граница отрезка
	// output:
	//	double - корень уравнения
	double methodNewton(double leftValue, double rightValue) const {
		const double eps = 0.001;
		double value = 1;
		double newValue = value;
		Polynomial secondDerivative = this->derivative().derivative();
		Polynomial poly2 = this->derivative();

		if (this->rootCalculation(leftValue) * secondDerivative.rootCalculation(leftValue) > 0) {
			value = leftValue;
		}
		else {
			value = rightValue;
		}

		if (this->rootCalculation(value) * secondDerivative.rootCalculation(value) > 0) {
			while (!(abs(this->rootCalculation(value) / poly2.rootCalculation(value)) < eps)) {
				newValue = value - this->rootCalculation(value) / poly2.rootCalculation(value);
				value = newValue;
			}
		}

		return newValue;
	}

	// Метод хорд и касательных
	double methodChordsAndTangents(double leftValue, double rightValue) const {
		double eps = 0.001;
		Polynomial firstDerivative = this->derivative();
		Polynomial secondDerivative = firstDerivative.derivative();

		if (this->rootCalculation(leftValue) * this->rootCalculation(rightValue) < 0) {
			while (abs(leftValue - rightValue) > (2 * eps)) {
				if ((this->rootCalculation(leftValue) * secondDerivative.rootCalculation(leftValue)) < 0) {
					leftValue = leftValue - this->rootCalculation(leftValue) * (leftValue - rightValue) / (this->rootCalculation(leftValue) - this->rootCalculation(rightValue));
				}
				else if ((this->rootCalculation(leftValue) * secondDerivative.rootCalculation(leftValue)) > 0) {
					leftValue = leftValue - (this->rootCalculation(leftValue) / firstDerivative.rootCalculation(leftValue));
				}

				if ((this->rootCalculation(rightValue) * secondDerivative.rootCalculation(rightValue)) < 0) {
					rightValue = rightValue - this->rootCalculation(rightValue) * (rightValue - leftValue) / (this->rootCalculation(rightValue) - this->rootCalculation(leftValue));
				}
				else if ((this->rootCalculation(rightValue) * secondDerivative.rootCalculation(rightValue)) > 0) {
					rightValue = rightValue - (this->rootCalculation(rightValue) / firstDerivative.rootCalculation(rightValue));
				}
			}

			return ((leftValue + rightValue) / 2);
		}
		else {
			return -1;
		}
	}

	// Ввод многочлена с клавиатуры
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

	// Перегрузка оператора >> для istream
	friend istream& operator>>(istream& is, Polynomial& poly) {
		int degree = 0;
		cout << "Введите степень многочлена: ";
		is >> degree;

		poly.coefficients.resize(degree + 1);

		for (int i = degree; i >= 0; i--) {
			cout << "Введите коэффициент при x^" << i << ": ";
			is >> poly.coefficients[i];
		}

		return is;
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

	// Перегрузка оператора << для ostream
	friend ostream& operator<<(ostream& os, const Polynomial& poly) {
		bool isFirstTerm = true;

		for (int i = poly.coefficients.size() - 1; i >= 0; i--) {
			if (poly.coefficients[i] != 0.0) {
				if (!isFirstTerm) {
					if (poly.coefficients[i] > 0) {
						os << " + ";
					}
					else {
						os << " - ";
					}
				}
				else {
					isFirstTerm = false;
					if (poly.coefficients[i] < 0) {
						os << "-";
					}
				}
				double absCoefficient = abs(poly.coefficients[i]);
				if (i == 0 || absCoefficient != 1.0) {
					os << absCoefficient;
				}
				if (i > 0) {
					os << "x";
					if (i > 1) {
						os << "^" << i;
					}
				}
			}
		}
		if (isFirstTerm) {
			os << "0";
		}

		return os;
	};
};
