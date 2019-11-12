#include "type_traits.hpp"
#include <type_traits>
#include <typeinfo>
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << LEON::bool_constant<true>::value << std::endl;

    return 0;
}