#include <iostream>
#include <numeric>  

using namespace std;

class Fraction {
private:
    int numerator;   
    int denominator; 

    void reduce() {
        int gcd = gcd(numerator, denominator); 
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    void input() {
        cout << "Введіть чисельник: ";
        cin >> numerator;
        cout << "Введіть знаменник: ";
        cin >> denominator;

        if (denominator == 0) {
            cerr << "Знаменник не може бути нульовим! Встановлено 1.\n";
            denominator = 1;
        }

        reduce();
    }

    void print() const {
        cout << numerator << "/" << denominator << "\n";
    }

    Fraction add(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.reduce();
        return result;
    }

    Fraction subtract(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        result.reduce();
        return result;
    }

    Fraction multiply(const Fraction& other) const {
        Fraction result;
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        result.reduce();
        return result;
    }

    Fraction divide(const Fraction& other) const {
        Fraction result;
        if (other.numerator == 0) {
            cerr << "Помилка: ділення на нуль!\n";
            result.numerator = 0;
            result.denominator = 1;
        }
        else {
            result.numerator = numerator * other.denominator;
            result.denominator = denominator * other.numerator;
            result.reduce();
        }
        return result;
    }
};

int main() {
    Fraction f1, f2;

    cout << "Введіть перший дріб:\n";
    f1.input();

    cout << "Введіть другий дріб:\n";
    f2.input();

    cout << "\nРезультати операцій:\n";

    cout << "Сума: ";
    f1.add(f2).print();

    cout << "Різниця: ";
    f1.subtract(f2).print();

    cout << "Добуток: ";
    f1.multiply(f2).print();

    cout << "Частка: ";
    f1.divide(f2).print();

    return 0;
}
