#include "type_traits.hpp"
#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <cstddef>

static_assert(std::is_same<LEON::remove_cv<const volatile int>::type,
                           int>::value, "foge");

struct Str
{
    int x;
};

int main(int argc, char** argv)
{
    using f = void();

    std::cout << std::boolalpha
              << LEON::is_null_pointer<const LEON::nullptr_t>::value << std::endl;
    std::cout << std::boolalpha
              << std::is_function<f>::value << std::endl;
    std::cout << std::boolalpha
              << LEON::is_function<void(int)>::value << std::endl;
    return 0;

}