#include "type_traits.hpp"
#include <type_traits>
#include <typeinfo>
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << typeid(std::is_void<const void>::type).name() << std::endl;
    std::cout << typeid(std::true_type::type).name() << std::endl;

    std::cout << typeid(LEON::is_void<void>::type).name() << std::endl;
    std::cout << typeid(LEON::false_type::type).name() << std::endl;
    return 0;

}