#include "type_traits.hpp"
#include "utility.hpp"
#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <cstddef>
#include <utility>

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
    // int a = LEON::declval<int>();
    return 0;
}