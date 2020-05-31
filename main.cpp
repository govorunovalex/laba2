#include "Complex.h"
#include "ComplexImpl.h"

int main() {
    Complex<long double> c0(1, 2);
    Complex<long double> c1(c0);
    Complex<long double> c2 = c1;
    std::cin >> c1 >> c2;
    std::cout << c1 << std::endl;
    std::cout << "c1 = " << c2.get_a() << "+" << c2.get_b() << "*i" << std::endl;
    std::cout << " c1 + c2 = " << c1 + c2 << std::endl;
    std::cout << " c1 - c2 = " << c1 - c2 << std::endl;
    std::cout << " c1 * c2 = " << c1 * c2 << std::endl;
    std::cout << " c1 / c2 = " << c1 / c2 << std::endl;
    std::cout << " r of c1 = " << c1.r() << std::endl;
    std::cout << " c1 ^ 3 = " << (c1 ^ 3) <<  " with k = 0" << std::endl;
    std::cout << " c1 ^ 0.1 = " << (c1 ^ 0.1f) << " with k = 0" << std::endl;
    std::cout << " c1 ^ -4.5 = " << (c1 ^ -4.5f) << " with k = 0" << std::endl;
    std::cout << " c1 ^ c2 = " << (c1 ^ c2) << std::endl;
    std::cout << " c1 ^ c2 in trigonometic form is: ";
    (c1 ^ c2).printTrig();
    std::cout << std::endl;

    return 0;
}
