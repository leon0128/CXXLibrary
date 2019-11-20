#include "type_traits.hpp"
#include "utility.hpp"
#include "limits.hpp"
// #include <type_traits>
#include <typeinfo>
#include <iostream>
// #include <climits>
// #include <cstddef>
// #include <utility>
// #include <limits>
// #include <initializer_list>

class CLASS
{

};

using FUNC = void;

// static_assert(LEON::is_constructible<void>::value,
//               ";ljas;jj;");


int main(int argc, char** argv)
{
    std::cout << std::boolalpha
              << "value: "
              << LEON::is_constructible<void>::value
              << std::endl;

    return 0;
}