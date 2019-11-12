namespace LEON
{

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

};