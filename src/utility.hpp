#pragma once

#include "type_traits.hpp"

namespace LEON
{
    // 宣言
    template<typename>
    struct add_rvalue_reference;

    // declval (c++11)
    // declval のヘルパー
    template<typename T>
    struct declval_helper
    {
        static const bool stop = false;
        static typename add_rvalue_reference<T>::type delegate();
    };
    // 指定された型の値を得る
    template<typename T>
    typename add_rvalue_reference<T>::type declval() noexcept
    {
        static_assert(declval_helper<T>::stop,
                      "incorrect usage of declval.");
        return declval_helper<T>::delegate();
    }
};