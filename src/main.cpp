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
    int y;
    int z;
};

int main(int argc, char** argv)
{
    std::max_align_t align;
    LEON::max_align_t align2;
    LEON::byte a;

    std::cout << offsetof(Str, y) << std::endl;
    std::cout << typeid(int).name() << std::endl;
    std::cout << typeid(LEON::byte).name() << std::endl;

    std::cout << LEON::is_void<void>::value << std::endl;
    std::cout << LEON::is_void<const void>::value << std::endl;

    return 0;

}