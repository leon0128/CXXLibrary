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

class U
{
public:
    explicit U(int){}
};

int main(int argc, char** argv)
{
    using type = LEON::add_rvalue_reference<int>::type;

    std::cout << std::boolalpha
              << std::is_same<type, int&&>::value << std::endl;

    // std::cout << std::boolalpha
    //           << std::is_same

    return 0;
}