#pragma once
#include "Complex.h"
#include <math.h>

template <typename T>
Complex<T>::Complex(const T& a, const T& b) :a(a), b(b) {}

template <typename T>
Complex<T>::Complex() :a(0), b(0) {}

template <typename T>
T& Complex<T>::get_a() { return a; }

template <typename T>
T& Complex<T>::get_b() { return b; }

template <typename T>
Complex<T>& Complex<T>::operator+=(const Complex & other) {
    a += other.a;
    b += other.b;
    return *this;
}

template <typename T>
Complex<T> Complex<T>::operator+(const Complex & other) {
    Complex result(*this);
    result += other;
    return result;
}

template <typename T>
Complex<T>& Complex<T>::operator-=(const Complex & other) {
    a -= other.a;
    b -= other.b;
    return *this;
}


template <typename T>
Complex<T> Complex<T>::operator-(const Complex & other) {
    Complex result(*this);
    result -= other;
    return result;
}

template <typename T>
Complex<T>& Complex<T>::operator*=(const Complex & other) {
    T temp_a = a;
    a = a * other.a - b * other.b;
    b = temp_a * other.b + other.a * b;
    return *this;
}

template <typename T>
Complex<T> Complex<T>::operator*(const Complex & other) {
    Complex result(*this);
    result *= other;
    return result;
}

template <typename T>
Complex<T>& Complex<T>::operator/=(const Complex & other) {
    T temp_a = a;
    a = (a * other.a - b * other.b) / (other.a * other.a - other.b * other.b);
    b = (temp_a * other.b - other.a * b) / (other.a * other.a - other.b * other.b);
    return *this;
}

template <typename T>
Complex<T> Complex<T>::operator/(const Complex & other) {
    Complex result(*this);
    result /= other;
    return result;
}

template <typename T>
T Complex<T>::r() {
    return sqrt(a * a + b + b);
}

template <typename T>
Complex<T>& Complex<T>::operator^=(T n) {
    T r = this->r();
    T phi = atan(b/a);

    r *= n;
    phi *= n;

    a = r * cos(phi);
    b = r * sin(phi);
    return *this;
}

template <typename T>
Complex<T> Complex<T>::operator^(T n) {
    Complex<T> result(*this);
    result ^= n;
    return result;
}

template <typename T>
Complex<T>& Complex<T>::operator^=(const Complex<T> other) {
    Complex<T> lnOfThis(
        log(sqrt(a * a + b * b)),
        atan(b / a)
    );

    Complex<T> powOfE(other);
    powOfE *= lnOfThis;

    T r = powOfE.a;
    T phi = powOfE.b;

    a = cos(phi) * r;
    b= sin(phi) * r;
    return *this;
}

template <typename T>
Complex<T> Complex<T>::operator^(const Complex<T> other) {
    Complex<T> result(*this);
    result ^= other;
    return result;
}

template <typename T>
void Complex<T>::printTrig() {
    T r = this->r();
    T phi = ( 180. * atan(b/a) )/ 3.141596; // from rads to grads

    std::cout << r << "(sinx(" << phi << ")+cos(" << phi << "))";
}