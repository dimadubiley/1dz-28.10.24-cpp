#include <iostream>
#include <stdexcept>

using namespace std;

class Drob
{
    int numerator;
    int denominator;

public:
    Drob(int num = 0, int denom = 1) : numerator(num), denominator(denom)
    {
        if (denom == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    void reduce()
    {
        int gcd = findGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
    }

    int findGCD(int a, int b) const
    {
        return b == 0 ? a : findGCD(b, a % b);
    }

    Drob operator+(const Drob& other) const
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Drob(num, denom);
    }

    Drob operator-(const Drob& other) const
    {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Drob(num, denom);
    }

    Drob operator*(const Drob& other) const
    {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Drob(num, denom);
    }

    Drob operator/(const Drob& other) const
    {
        if (other.numerator == 0)
        {
            throw invalid_argument("Cannot divide by zero.");
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Drob(num, denom);
    }

    Drob& operator++()
    {
        numerator += denominator;
        reduce();
        return *this;
    }

    Drob operator++(int)
    {
        Drob temp = *this;
        numerator += denominator;
        reduce();
        return temp;
    }

    Drob& operator--()
    {
        numerator -= denominator;
        reduce();
        return *this;
    }

    Drob operator--(int)
    {
        Drob temp = *this;
        numerator -= denominator;
        reduce();
        return temp;
    }

    Drob& operator*()
    {
        numerator *= denominator;
        reduce();
        return *this;
    }

    Drob operator*(int)
    {
        Drob temp = *this;
        numerator *= denominator;
        reduce();
        return temp;
    }

    void Print() const
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Drob a(3, 4);
    Drob b(5, 6);

    Drob sum = a + b;
    Drob diff = a - b;
    Drob prod = a * b;
    Drob quot = a / b;

    cout << "a + b = ";
    sum.Print();

    cout << "a - b = ";
    diff.Print();

    cout << "a * b = ";
    prod.Print();

    cout << "a / b = ";
    quot.Print();

    cout << "\nIncrement and decrement operations:" << endl;

    cout << "++a = ";
    (++a).Print();

    cout << "a++ = ";
    (a++).Print();
    cout << "After a++, a = ";
    a.Print();

    cout << "--b = ";
    (--b).Print();

    cout << "b-- = ";
    (b--).Print();
    cout << "After b--, b = ";
    b.Print();

}
