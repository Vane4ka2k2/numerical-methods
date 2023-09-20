#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
	//������ �������������
	vector<double> coefficients;

public:
	//����������� �� ���������, ������ ��������� � �������� ��������������
	Polynomial() : coefficients{ 0 } {};

	//����������� � ��������� ������� �������������
	Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {};

	//����������
	~Polynomial() {};

	//���������� ��������� ��������
	Polynomial operator+ (const Polynomial& other) const {
		vector<double> result(max(coefficients.size(), other.coefficients.size()), 0);

		for (int i = 0; i < coefficients.size(); i++) {
			result[i] += coefficients[i];
		}

		for (int i = 0; i < other.coefficients.size(); i++) {
			result[i] += other.coefficients[i];
		}

		return Polynomial(result);
	};

	//���������� ��������� ���������
	Polynomial operator- (const Polynomial& other) const {
		vector<double> result(max(coefficients.size(), other.coefficients.size()), 0);

		for (int i = 0; i < coefficients.size(); i++) {
			result[i] += coefficients[i];
		}

		for (int i = 0; i < other.coefficients.size(); i++) {
			result[i] -= other.coefficients[i];
		}

		return Polynomial(result);
	};

	//���������� ��������� ���������
	Polynomial operator* (const Polynomial& other) const {
		vector<double> result(coefficients.size() + other.coefficients.size() - 1, 0);

		for (int i = 0; i < coefficients.size(); i++) {
			for (int j = 0; j < other.coefficients.size(); j++) {
				result[i + j] += coefficients[i] * other.coefficients[j];
			}
		}

		return Polynomial(result);
	};

	//���������� ��������� ��������� ��� �����
	Polynomial operator* (const double& other) const {
		vector<double> result(coefficients.size(), 0);

		for (int i = 0; i < coefficients.size(); i++) {
				result[i] += coefficients[i] * other;
		}

		return Polynomial(result);
	};

	//���������� ��������� �������
	Polynomial operator/ (const Polynomial& other) const {
		vector<double> result;
		vector<double> dividend = coefficients;

		while (dividend.size() >= other.coefficients.size()) {
			double coeff = dividend[0] / other.coefficients[0]; result.push_back(coeff);

			for (int i = 0; i < other.coefficients.size(); i++) {
				dividend[i] -= coeff * other.coefficients[i];
			}

			while (!dividend.empty() && dividend[0] == 0) {
				dividend.erase(dividend.begin());
			}
		}

		if (result.empty()) {
			result.push_back(0);
		}

		return Polynomial(result);
	};

	//���������� ��������� ������� ��� �����
	Polynomial operator/ (const double& other) const {
		vector<double> result(coefficients.size(), 0);

		for (int i = 0; i < coefficients.size(); i++) {
			result[i] += coefficients[i] / other;
		}

		return Polynomial(result);
	};

	//���������� ��������� ������
	friend ostream& operator<< (ostream& os, const Polynomial& poly) {
		for (int i = poly.coefficients.size() - 1; i >= 0; i--) {
			if (poly.coefficients[i] != 0) {
				if (i < poly.coefficients.size() - 1) {
					if (poly.coefficients[i] > 0) {
						os << "+";
					}
				}
				if (i > 0) {
					if (poly.coefficients[i] != 1) {
						os << poly.coefficients[i];
					}
					os << "x";
					if (i > 1) {
						os << "^" << i;
					}
				}
				else {
					os << poly.coefficients[i];
				}
			}
		}

		return os;
	};
};