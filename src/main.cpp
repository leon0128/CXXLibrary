#include "type_traits.hpp"
#include <type_traits>
#include <typeinfo>
#include <iostream>

static_assert(std::is_same<LEON::remove_cv<const volatile int>::type,
                           int>::value, "foge");

int main(int argc, char** argv)
{
    std::cout << typeid(std::is_void<const void>::type).name() << std::endl;
    std::cout << typeid(std::true_type::type).name() << std::endl;

    std::cout << LEON::is_void<void>::value << std::endl;
    std::cout << LEON::is_void<const void>::value << std::endl;

    return 0;

}