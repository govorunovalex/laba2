#pragma once
#include <iostream>

template <typename T>
class Complex {
	T a, b;
public:
	Complex(const T& a, const T& b);
	friend std::ostream& operator<<(std::ostream& out, const Complex<T>& c) {
		out << c.a << ((c.b < 0) ? "-" : "+") << ((c.b < 0) ? -c.b : c.b) << "*i";
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Complex<T>& c) {
		in >> c.a >> c.b;
		return in;
	}
	Complex();
	Complex(const Complex& c) = default;
	Complex& operator=(const Complex& other) = default;



	T& get_a();
	T& get_b();
	Complex& operator+=(const Complex& other);
	Complex operator+(const Complex& other);
	Complex& operator-=(const Complex& other);

	Complex operator-(const Complex& other);
	Complex& operator*=(const Complex& other);

	Complex operator*(const Complex& other);
	Complex& operator/=(const Complex& other);

	Complex operator/(const Complex& other);
	T r();
	Complex<T>& operator^=(T n);
	Complex<T> operator^(T n);
	Complex<T>& operator^=(const Complex<T> other);
	Complex<T> operator^(const Complex<T> other);
	void printTrig();
};
