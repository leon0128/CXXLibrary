#pragma once

namespace LEON
{
    /*
    * ヘルパークラス
    */

    // integral_constant (c++11)
    // 整数定数を表す構造体
    template<typename T, T v>
    struct integral_constant
    {
        static constexpr T value = v;

        using value_type = T;
        using type       = integral_constant<T, v>;

        // c++14 (c++11 では noexpect 修飾がない)
        constexpr operator value_type() noexcept {return value;}
        // c++14
        constexpr value_type operator()() const noexcept {return value;}
    };

    // bool_constant (c++17)
    // 真理値型の定数を表す構造体
    template<bool B>
    using bool_constant = integral_constant<bool, B>;

    // true_type (c++11)
    // true を表す定数型の構造体
    // c++17 (c++14 までは integral_constant<bool, true> を使用)
    using true_type = bool_constant<true>;
    // false_type (c++11)
    // false を表す定数型の構造体
    // c++17 (c++14 までは integral_constant<bool, false> を使用)
    using false_type = bool_constant<false>;

    /*
    * 基本的な型
    */

    // is_void (c++11)
    // is_void のヘルパー
    template<typename>
    struct is_void_helper:
        public false_type{};
    template<>
    struct is_void_helper<void>:
        public true_type{};
    // is_void (c++11)
    // 型が void 型 (cv 修飾許容) なら true_type から派生, そうでなければ false_type から派生
    template<typename T>
    struct remove_cv;
    template<typename T>
    struct is_void:
        public is_void_helper<typename remove_cv<T>::type>{};
    // is_void_t (c++17) (c++11 だと使用不可のテンプレートの為、未実装)
    // template<typename T>
    // inline constexpr bool is_void_t = is_void<T>::value;

    // is_null_pointer (c++14)
    // is_null_pointer のヘルパー
    template<typename>
    struct is_null_pointer_helper{};


    /*
    * const - volatile の変更
    */

    // remove_const (c++11)
    // 型の const 修飾の除去
    template<typename T>
    struct remove_const
        {using type = T;};
    template<typename T>
    struct remove_const<T const>
        {using type = T;};
    // remove_volatile (c++11)
    // 型の volatile 修飾の除去
    template<typename T>
    struct remove_volatile
        {using type = T;};
    template<typename T>
    struct remove_volatile<T volatile>
        {using type = T;};
    // remove_cv (c++11)
    // 型の cv 修飾の除去
    template<typename T>
    struct remove_cv
    {
        using type 
            = typename remove_const<typename remove_volatile<T>::type>::type;
    };
   

};