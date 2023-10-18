# numerical-methods
## Поля
- `coefficients` - вектор коэффициентов типа double. Индекс вектора соответствует степени x.

## Конструкторы
- `Polynomial()` - пустой конструктор
- `Polynomial(const vector<double>& coeefs)` - конструктор, в который передаётся вектор коэффициентов для заполнения поля `coefficients`. 

## Деструктор
- `~Polynomial()` - пустой деструктор

## Методы
- `void removeLeadingZeros()` - метод для удаления незначащих нулей
- `void roundCoefficients()` - метод для округления коэффициентов вектора, с точностью до 3-ёх знаков.
- `Polynomial derivative() const` - метод для взятия производной многочлена. Возвращает новый многочлен.
- `Polynomial gcd(const Polynomial& other) const` - метод для нахождения НОД двух многочленов. Передаётся второй многочлен. Возвращает новый многочлен.
- `Polynomial removeMultiplicity()` - метод для устранения кратности корней многочлена. Возвращает новый многочлен.
- `void input()` - метод для ввода многочлена с клавиатуры.
- `void print()` - метод для вывод многочлена в консоль.

## Перегруженные операторы
### Логические операторы
- `bool operator!=(const Polynomial& other) const` - перегрузка оператора != для сравнения двух многочленов.
- `bool operator==(const Polynomial& other) const` - перегрузка оператора == для сравнения двух многочленов.
- `bool operator>(const Polynomial& other) const` - перегрузка оператора > для сравнения двух многочленов.

### Арифметические операторы
- `Polynomial operator+(const Polynomial& other) const` - перегрузка оператора для сложения двух многочленов. Передаётся второй многочлен. Возвращается новый многочлен.
- `Polynomial operator+(const double& scalar) const` - перегрузка оператора для сложения многочлена с числом. Передаётся число. Возвращается новый многочлен.
- `Polynomial operator-(const Polynomial& other) const` - перегрузка оператора для вычитания двух многочленов. Передаётся второй многочлен. Возвращается новый многочлен.
- `Polynomial operator-(const double& scalar) const` - перегрузка оператора для вычитания многочлена с числом. Передаётся число. Возвращается новый многочлен.
- `Polynomial operator*(const Polynomial& other) const` - перегрузка оператора для умножения двух многочленов. Передаётся второй многочлен. Возвращается новый многочлен.
- `Polynomial operator*(const double& scalar) const` - перегрузка оператора для умножения многочлена на число. Передаётся число. Возвращается новый многочлен.
- `Polynomial operator/(const Polynomial& other) const` - перегрузка оператора для деления двух многочленов. Передаётся второй многочлен. Возвращается новый многочлен (частное).
- `Polynomial operator/(const double& scalar) const` - перегрузка оператора для деления многочлена на число. Передаётся число. Возвращается новый многочлен (частное).
- `Polynomial operator%(const Polynomial& other) const` - перегрузка оператора для деления двух многочленов. Передаётся второй многочлен. Возвращается новый многочлен (остаток).

### Перегрузка потоков
- `friend istream& operator>>(istream& is, Polynomial& poly)` - перегрузка оператора >> для istream для ввода многочлена в поток.
- `friend ostream& operator<<(ostream& os, Polynomial& poly)` - перегрузка оператора << для ostream для вывода многочлена в поток.