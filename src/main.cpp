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

static_assert(LEON::is_assignable<int&, int>::value,
              "false");

int main(int argc, char** argv)
{
    std::cout << "type: " << LLONG_MIN << std::endl;
    return 0;
}