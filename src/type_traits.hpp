namespace LEON
{

// c++11
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

// c++17
// 真理値型の定数を表す構造体
template<bool B>
using bool_constant = integral_constant<bool, B>;

// c++11
// true を表す定数型の構造体
// c++17 (c++14 までは integral_constant<bool, true> を使用)
using true_type = bool_constant<true>;
// c++11
// false を表す定数型の構造体
// c++17 (c++14 までは integral_constant<bool, false> を使用)
using false_type = bool_constant<false>;

};