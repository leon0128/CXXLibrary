#include "type_traits.hpp"
#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <cstddef>

static_assert(std::is_same<LEON::remove_cv<const volatile int>::type,
                           int>::value, "foge");

int main(int argc, char** argv)
{
    std::cout << std::boolalpha
              << LEON::is_null_pointer<const LEON::nullptr_t>::value << std::endl;
    std::cout << std::boolalpha
              << std::is_null_pointer<const std::nullptr_t>::value << std::endl;
    std::cout << std::boolalpha
              << std::is_pointer<const int*>::value << std::endl;
    return 0;

}