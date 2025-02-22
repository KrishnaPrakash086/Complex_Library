#include <iostream>
#include <cmath>

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
  private:
    double a;
    double b;

  public:
    // Constructors & Desctructor
    Complex() noexcept;
    Complex(double, double) noexcept;
    Complex(const Complex&) noexcept;

    inline double real() const noexcept { return a; }
    inline double imag() const noexcept { return b; }

    friend double real(const Complex&) noexcept;
    friend double imag(const Complex&) noexcept;

    // Assignment operator
    Complex& operator=(const Complex&) noexcept;

    // Binary arithmetic operators
    Complex& operator+=(const Complex&) noexcept;
    Complex& operator-=(const Complex&) noexcept;
    Complex& operator*=(const Complex&) noexcept;
    Complex& operator/=(const Complex&);

    // Arithmetic
    friend Complex operator+(const Complex&, const Complex&) noexcept;
    friend Complex operator-(const Complex&, const Complex&) noexcept;
    friend Complex operator*(const Complex&, const Complex&) noexcept;
    friend Complex operator/(const Complex&, const Complex&);

    // Logical
    friend bool operator==(const Complex&, const Complex&) noexcept;
    friend bool operator!=(const Complex&, const Complex&) noexcept;

    // Absolute value
    double abs() const noexcept;
    friend double abs(const Complex&) noexcept;

    // Argument value
    double arg() const noexcept;
    friend double arg(const Complex&) noexcept;

    // Conjugate value
    Complex conj() const noexcept;
    friend Complex conj(const Complex&) noexcept;

    // Output
    friend std::ostream& operator<<(std::ostream&, const Complex&);
};

#endif
