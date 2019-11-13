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
    int func();
};
enum class E
{

};

union U
{

};

int main(int argc, char** argv)
{
    using f = void();

    std::cout << std::boolalpha
              << std::is_union<const U>::value << std::endl;
    std::cout << std::boolalpha
              << LEON::is_union<const U>::value << std::endl;
    return 0;

}