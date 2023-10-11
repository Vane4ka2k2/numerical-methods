#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    int degree;                     //степень многочлена
    vector<double> coefficients;    //вектор коэффициентов

public:
    //конструкторы и деструктор
    Polynomial() : degree(0), coefficients(1, 0.0) {}                                               //конструктор по умолчанию, создаёт нулевой многочлен
    Polynomial(int _degree) : degree(_degree), coefficients(_degree + 1, 0.0) {}                    //создаёт многочлен заданной степени
    Polynomial(const vector<double>& coeffs) : degree(coeffs.size() - 1), coefficients(coeffs) {}   //создаёт многочлен из вектора коэффициентов
    ~Polynomial() {}                                                                                //деструктор

    int getDegree() const {
        return degree;  //возвращает степень многочлена
    }

    //очевидно
    void input() {
        cout << "Введите степень многочлена: ";
        cin >> degree;

        coefficients.resize(degree + 1);

        for (int i = degree; i >= 0; i--) {
            cout << "Введите коэффициент при x^" << i << ": ";
            cin >> coefficients[i];
        }
    }

    //аналогично
    void print() const {
        bool isFirstTerm = true;

        for (int i = degree; i >= 0; i--) {
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

    //перегрузка операторов
    //сложение
    Polynomial operator+ (const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        vector<double> resultCoeffs(maxDegree + 1, 0.0);

        for (int i = 0; i <= maxDegree; i++) {
            if (i <= degree) resultCoeffs[i] += coefficients[i];
            if (i <= other.degree) resultCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }

    //вычитание
    Polynomial operator- (const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        vector<double> resultCoeffs(maxDegree + 1, 0.0);

        for (int i = 0; i <= maxDegree; i++) {
            if (i <= degree) resultCoeffs[i] += coefficients[i];
            if (i <= other.degree) resultCoeffs[i] -= other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }

    //умножение
    Polynomial operator* (const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        vector<double> resultCoeffs(resultDegree + 1, 0.0);

        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultCoeffs);
    }

    //умножение на число
    Polynomial operator* (const double& scalar) const {
        vector<double> resultCoeffs(coefficients);

        for (double& coeff : resultCoeffs) {
            coeff *= scalar;
        }

        return Polynomial(resultCoeffs);
    }

    //деление
    Polynomial operator/ (const Polynomial& other) {
        double tempDegree = degree;

        // Проверяем, что делитель не является нулевым многочленом
        if (other.getDegree() == 0 && other.coefficients[0] == 0.0) {
            throw invalid_argument("Деление на нулевой многочлен");
        }

        // Если степень текущего многочлена меньше степени делителя,
        // результат деления будет нулевым многочленом.
        if (tempDegree < other.getDegree()) {
            return Polynomial(); // Результат деления меньшего многочлена на больший - ноль.
        }

        // Создаем вектор коэффициентов для результирующего многочлена
        vector<double> resultCoeffs(tempDegree - other.getDegree() + 1, 0.0);

        // Создаем временную копию коэффициентов текущего многочлена
        vector<double> tempCoeffs(coefficients);

        // Пока степень текущего многочлена больше или равна степени делителя
        while (tempDegree >= other.getDegree()) {
            // Определяем текущую степень для вычисления частного
            int currentDegree = tempDegree - other.getDegree();

            // Вычисляем частное
            double quotient = tempCoeffs[tempDegree] / other.coefficients[other.getDegree()];

            // Записываем частное в результирующий многочлен
            resultCoeffs[currentDegree] = quotient;

            // Вычитаем произведение делителя на частное из текущего многочлена
            for (int i = 0; i <= other.getDegree(); i++) {
                tempCoeffs[i + currentDegree] -= quotient * other.coefficients[i];
            }

            // Удаляем нулевые коэффициенты в конце многочлена
            while (tempCoeffs.back() == 0.0 && degree > 0) {
                tempCoeffs.pop_back();
                tempDegree--;
            }
        }

        // Возвращаем результирующий многочлен
        return Polynomial(resultCoeffs);
    }

    //остаток от деления
    Polynomial operator% (const Polynomial& other) const {
        vector<double> quotient(coefficients.size(), 0);
        if (other.coefficients.empty() || other.coefficients[0] == 0) {
            throw runtime_error("Пустой или нулевой делитель.");
        }
        vector<double> dividend = coefficients;
        while (dividend.size() >= other.coefficients.size() && dividend[0] != 0) {
            double coeff = dividend[0] / other.coefficients[0];
            quotient[dividend.size() - other.coefficients.size()] = coeff;
            vector<double> temp(dividend.size(), 0);
            for (int i = 0; i < other.coefficients.size(); i++) {
                temp[i] = coeff * other.coefficients[i];
            }
            for (int i = 0; i < other.coefficients.size(); i++) {
                dividend[i] -= temp[i];
            }
            while (!dividend.empty() && dividend[0] == 0) {
                dividend.erase(dividend.begin());
            }
        }
        return Polynomial(dividend);
    };

    //получение производной
    Polynomial derivative() {
        int n = coefficients.size();
        if (n <= 1) {
            return Polynomial(0);
        }
        vector<double> derivativeCoeffs(n - 1, 0.0);
        for (int i = 0; i < n - 1; i++) {
            derivativeCoeffs[i] = (n - i - 1) * coefficients[i];
        }
        return Polynomial(derivativeCoeffs);
    }
};
