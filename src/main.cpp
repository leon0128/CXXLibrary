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
              << LEON::is_null_pointer<int>::value << std::endl;

    return 0;

}