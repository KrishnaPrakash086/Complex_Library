#include "Complex.h"

Complex::Complex() noexcept
    : a(0), b(0) {}

Complex::Complex(double real, double imaginary) noexcept
    : a(real), b(imaginary) {}

Complex::Complex(const Complex& complex) noexcept
    : a(complex.a), b(complex.b) {}

double real(const Complex& complex) noexcept { return complex.a; }
double imag(const Complex& complex) noexcept { return complex.b; }

Complex& Complex::operator=(const Complex& other) noexcept {
    a = other.a;
    b = other.b;
    return *this;
}

Complex& Complex::operator+=(const Complex& other) noexcept {
    a += other.a;
    b += other.b;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) noexcept {
    a -= other.a;
    b -= other.b;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) noexcept {
    a = (a * other.a) - (b * other.b);
    b = (a * other.b) + (b * other.a);
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    double den = pow(other.a, 2) + pow(other.b, 2);
    double newA = ((a * other.a) + (b * other.b)) / den;
    double newB = ((b * other.a) - (a * other.b)) / den;
    *this = Complex(newA, newB);
    return *this;
}

Complex operator+(const Complex& c1, const Complex& c2) noexcept {
    return Complex(c1.a + c2.a, c1.b + c2.b);
}

Complex operator-(const Complex& c1, const Complex& c2) noexcept {
    return Complex(c1.a - c2.a, c1.b - c2.b);
}


Complex operator*(const Complex& c1, const Complex& c2) noexcept {
    double a = (c1.a * c2.a) - (c1.b * c2.b);
    double b = (c1.a * c2.b) + (c1.b * c2.a);
    return Complex(a, b);
}

Complex operator/(const Complex& c1, const Complex& c2) {
    double den = pow(c2.a, 2) + pow(c2.b, 2);
    if (den == 0) {
        return Complex(nan(""), nan(""));
    }
    double newA = ((c1.a * c2.a) + (c1.b * c2.b)) / den;
    double newB = ((c1.b * c2.a) - (c1.a * c2.b)) / den;
    return Complex(newA, newB);
}

bool operator==(const Complex& c1, const Complex& c2) noexcept {
    return (c1.a == c2.a && c1.b == c2.b);
}

bool operator!=(const Complex& c1, const Complex& c2) noexcept {
    return (c1.a != c2.a || c1.b != c2.b);
}

double Complex::abs() const noexcept {
    return pow((pow(a, 2) + pow(b, 2)), 0.5);
}

double abs(const Complex& complex) noexcept {
    return pow((pow(complex.a, 2) + pow(complex.b, 2)), 0.5);
}

double Complex::arg() const noexcept {
    return atan(b / a);
}

double arg(const Complex& complex) noexcept {
    return atan(complex.b / complex.a);
}

Complex Complex::conj() const noexcept {
    return Complex(a, -b);
}

Complex conj(const Complex& complex) noexcept {
    return Complex(complex.a, -complex.b);
}

std::ostream& operator<<(std::ostream& stream, const Complex& complex) {
    if (complex.b >= 0) {
        return stream << complex.a << "+" << complex.b << "i";
    } else {
        return stream << complex.a << complex.b << "i";
    }
}
