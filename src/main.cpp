#include "type_traits.hpp"
#include "utility.hpp"
#include "limits.hpp"
#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <cstddef>
#include <utility>
#include <limits>

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

struct C
{
};

class U
{
public:
    explicit U(int){}
};

static_assert(std::is_same<LEON::add_lvalue_reference_t<int&&>,
                           int&>::value, "hoge");


int main(int argc, char** argv)
{
    std::cout << "type: "
              << typeid(std::make_unsigned<E>::type).name() << std::endl;

    std::cout << "type: "
              << typeid(LEON::make_unsigned<E>::type).name() << std::endl;
    
    std::cout << "value: ";
            //   << std::numeric_limits<C>::signaling_NaN() << std::endl;

      LEON::numeric_limits<const bool>::digits;
    std::numeric_limits<bool>::round_style;
    return 0;
}