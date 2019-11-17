#pragma once

#include "type_traits.hpp"

namespace LEON
{
    // 宣言
    template<typename>
    struct remove_reference;
    template<typename>
    struct add_rvalue_reference;

    /*
    * 転送と移動
    */

    // forward (c++11)
    // 関数テンプレートの引数を転送
    // template<typename T>
    // T&& forward(typename )

    /*
    * 型の値
    */

    // declval (c++11)
    // declval のヘルパー
    template<typename T>
    struct declval_helper
    {
        static const bool stop = false;
        static typename add_rvalue_reference<T>::type delegate();
    };
    // declval (c++11)
    // 指定された型の値を得る (この関数は評価されてはならない)
    template<typename T>
    typename add_rvalue_reference<T>::type declval() noexcept
    {
        static_assert(declval_helper<T>::stop,
                      "incorrect usage of declval.");
        return declval_helper<T>::delegate();
    }
};