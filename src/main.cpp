#include "type_traits.hpp"
#include "utility.hpp"
#include "limits.hpp"
// #include <type_traits>
// #include <typeinfo>
#include <iostream>
// #include <climits>
// #include <cstddef>
// #include <utility>
// #include <limits>
// #include <initializer_list>

struct S
{
    ~S(){}
};

static_assert(LEON::is_trivially_destructible<S>::value,
              "false");

int main(int argc, char** argv)
{
    std::cout << "type: " << LLONG_MIN << std::endl;
    return 0;
}