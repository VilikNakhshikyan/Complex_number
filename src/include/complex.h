#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <ostream>
class Complex
{
public:
    Complex(double = 0, double = 0);
    Complex operator+(const Complex &);
    Complex operator-(const Complex &);
    Complex operator*(const Complex &);
    Complex operator/(const Complex &);
    Complex &operator+=(const Complex &);
    Complex &operator=(const Complex &);
    Complex &operator-=(const Complex &);
    Complex &operator*=(const Complex &);
    Complex &operator/=(const Complex &);
    Complex operator++(int);
    Complex &operator++();
    Complex operator--(int);
    Complex &operator--();
    bool operator==(const Complex &);
    friend std::ostream &operator<<(std::ostream &, const Complex &);

private:
    double m_rez;
    double m_imz;
};

#endif //_COMPLEX_H_