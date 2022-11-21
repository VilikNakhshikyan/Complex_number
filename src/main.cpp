#include "include/complex.h"
#include <iostream>
int main()
{
    Complex a(2.3, -3.2);
    Complex b(2.3, 5.2);
    std::cout << (a+b) << std::endl;
    std::cout << (a-b) << std::endl;
    std::cout << (a/b) << std::endl;
    std::cout << (a*b) << std::endl;
    std::cout << a++ << std::endl;
    std::cout << ++a << std::endl;
}