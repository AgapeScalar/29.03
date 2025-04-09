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
        cout << "������ ���������: ";
        cin >> numerator;
        cout << "������ ���������: ";
        cin >> denominator;

        if (denominator == 0) {
            cerr << "��������� �� ���� ���� ��������! ����������� 1.\n";
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
            cerr << "�������: ������ �� ����!\n";
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

    cout << "������ ������ ���:\n";
    f1.input();

    cout << "������ ������ ���:\n";
    f2.input();

    cout << "\n���������� ��������:\n";

    cout << "����: ";
    f1.add(f2).print();

    cout << "г�����: ";
    f1.subtract(f2).print();

    cout << "�������: ";
    f1.multiply(f2).print();

    cout << "������: ";
    f1.divide(f2).print();

    return 0;
}
