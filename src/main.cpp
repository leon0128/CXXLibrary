#include "type_traits.hpp"
#include <type_traits>
#include <typeinfo>
#include <iostream>

int main(int argc, char** argv)
{
    using int_zero = std::integral_constant<int, 0>;

    using int_Zero = LEON::integral_constant<int, 0>;

    std::cout << "std::typeid:   " << typeid(int_zero::value_type()).name() << std::endl;
    std::cout << "LEON::typeid: " << typeid(int_Zero::value_type()).name() << std::endl;

    return 0;
}