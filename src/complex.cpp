#include "include/complex.h"
#include <iostream>
#include <cmath>
Complex::Complex(double rez, double imz )
    : m_rez{rez}, m_imz{imz} {}

Complex &Complex::operator=(const Complex &other)
{
    if (*this == other)
    {
        return *this;
    }
    m_rez = other.m_rez;
    m_imz = other.m_imz;
    return *this;
}

Complex Complex::operator+(const Complex &other)
{
    return (Complex(m_rez + other.m_rez, m_imz + other.m_imz));
}

Complex Complex::operator-(const Complex &other)
{
    return (Complex(m_rez - other.m_rez, m_imz - other.m_imz));
}

Complex Complex::operator*(const Complex &other)
{
    double tot_rez = m_rez * other.m_rez - m_imz * other.m_imz;
    double tot_imz = m_rez * other.m_imz + m_imz * other.m_rez;
    return (Complex(tot_rez, tot_imz));
}

Complex Complex::operator/(const Complex &other)
{
    double tem_dev = pow(other.m_rez, 2) + pow(other.m_imz, 2);
    double tot_rez = m_rez * other.m_rez + m_imz * other.m_imz;
    double tot_imz = m_imz * other.m_rez - m_rez * other.m_imz;
    return (Complex(tot_rez / tem_dev, tot_imz / tem_dev));
}

Complex &Complex::operator+=(const Complex &other)
{
    *this = *this + other;
    return *this;
}

Complex &Complex::operator-=(const Complex &other)
{
    *this = *this - other;
    return *this;
}

Complex &Complex::operator*=(const Complex &other)
{
    *this = *this * other;
    return *this;
}

Complex &Complex::operator/=(const Complex &other)
{
    *this = *this / other;
    return *this;
}

Complex &Complex::operator++()
{
    m_rez += 1;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex temp(*this);
    m_rez += 1;
    return temp;
}

Complex &Complex::operator--()
{
    m_rez -= 1;
    return *this;
}

Complex Complex::operator--(int)
{
    Complex temp(*this);
    m_rez -= 1;
    return temp;
}

bool Complex::operator==(const Complex &other)
{
    if (m_rez == other.m_rez && m_imz == other.m_imz)
        return true;
    return false;
}

std::ostream &operator<<(std::ostream &out,const Complex &my)
{
    char plus = 0;
    if (my.m_imz > 0)
        plus = '+';
    if(my.m_imz == 0 && my.m_rez == 0)
    {
        out << 0;
        return out;
    }
    else if (my.m_rez == 0)
    {
        out << plus << my.m_imz<<'i';
        return out;
    }
    else if (my.m_imz == 0)
    {
        out << my.m_rez;
        return out;
    }
    out << my.m_rez << plus << my.m_imz << 'i';
    return out;
}