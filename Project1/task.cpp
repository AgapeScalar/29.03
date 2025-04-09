#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;   
    int denominator; 

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
        if (denominator < 0) { 
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) {
        numerator = num;
        denominator = den == 0 ? 1 : den; 
        simplify();
    }

    void input() {
        cout << "Введіть чисельник: ";
        cin >> numerator;
        cout << "Введіть знаменник: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Знаменник не може бути нулем. Встановлено 1 за замовчуванням.\n";
            denominator = 1;
        }
        simplify();
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction add(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction subtract(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction multiply(const Fraction& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction divide(const Fraction& other) const {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }
};

int main() {
    Fraction a, b;

    cout << "Введення першого дробу:\n";
    a.input();

    cout << "Введення другого дробу:\n";
    b.input();

    Fraction sum = a.add(b);
    Fraction diff = a.subtract(b);
    Fraction prod = a.multiply(b);
    Fraction quot = a.divide(b);

    cout << "\nРезультати:\n";
    cout << "Сума: ";
    sum.print();

    cout << "Різниця: ";
    diff.print();

    cout << "Добуток: ";
    prod.print();

    cout << "Частка: ";
    quot.print();

    return 0;
}
