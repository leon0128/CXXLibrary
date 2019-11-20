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

class CLASS
{

};

using FUNC = void;

static_assert(LEON::is_constructible<FUNC>::value,
              ";ljas;jj;");


int main(int argc, char** argv)
{
    return 0;
}