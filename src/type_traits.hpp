namespace LEON
{

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

// 真理値型の定数を表す構造体
template<bool B>
using bool_constant = integral_constant<bool, B>;



};