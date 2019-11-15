#pragma once

#include "cstddef.hpp"
#include <utility>

namespace LEON
{
    // 宣言
    template<typename>
    struct remove_cv;
    template<typename>
    struct is_function;
    template<typename>
    struct is_scalar;
    template<typename, unsigned = 0>
    struct extent;

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
    struct is_void:
        public is_void_helper<typename remove_cv<T>::type>{};
    // is_void_t (c++17) 
    // (c++11 だと使用不可の構文の為、未実装)

    // is_null_pointer (c++14)
    // is_null_pointer のヘルパー
    template<typename>
    struct is_null_pointer_helper:
        public false_type{};
    template<>
    struct is_null_pointer_helper<nullptr_t>:
        public true_type{};
    // is_null_pointer (c++11)
    // 型が nullptr_t なら true_type から派生、 そうでなければ false_type から派生
    template<typename T>
    struct is_null_pointer:
        public is_null_pointer_helper<typename remove_cv<T>::type>{};
    // is_null_pointer_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_integral (c++11)
    // is_integral のヘルパー
    template<typename T>
    struct is_integral_helper:
        public false_type{};
    template<> struct is_integral_helper<bool>               : public true_type{};
    template<> struct is_integral_helper<char>               : public true_type{};
    template<> struct is_integral_helper<signed char>        : public true_type{};
    template<> struct is_integral_helper<unsigned char>      : public true_type{};
    template<> struct is_integral_helper<char16_t>           : public true_type{};
    template<> struct is_integral_helper<char32_t>           : public true_type{};
    template<> struct is_integral_helper<wchar_t>            : public true_type{};
    template<> struct is_integral_helper<signed short>       : public true_type{};
    template<> struct is_integral_helper<unsigned short>     : public true_type{};
    template<> struct is_integral_helper<signed int>         : public true_type{};
    template<> struct is_integral_helper<unsigned int>       : public true_type{};
    template<> struct is_integral_helper<signed long>        : public true_type{};
    template<> struct is_integral_helper<unsigned long>      : public true_type{};
    template<> struct is_integral_helper<signed long long>   : public true_type{};
    template<> struct is_integral_helper<unsigned long long> : public true_type{};
    // is_integral (c+11)
    // 型が 整数型 (cv 修飾許容) なら true_type から派生、そうでなければ false_type から派生    // 
    template<typename T>
    struct is_integral:
        public is_integral_helper<typename remove_cv<T>::type>{};
    // is_integral_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_floating_point (c++11)
    // is_floating_point のヘルパー
    template<typename>
    struct is_floating_point_helper:
        public false_type{};
    template<> struct is_floating_point_helper<float>       : public true_type{};
    template<> struct is_floating_point_helper<double>      : public true_type{};
    template<> struct is_floating_point_helper<long double> : public true_type{};
    // is_floating_point (c++11)
    // 型が 浮動小数点型 (cv 修飾許容) なら true_type から派生、そうでなければ false_type から派生
    template<typename T>
    struct is_floating_point:
        public is_floating_point_helper<typename remove_cv<T>::type>{};
    // is_floating_point_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_array (c++11)
    // 型が 配列型なら true_type から派生し、そうでないなら false_type から派生
    template<typename>
    struct is_array : public false_type{};
    template<typename T, size_t sz>
    struct is_array<T[sz]>: 
        public true_type{};
    template<typename T>
    struct is_array<T[]>:
        public true_type{};
    // is_array_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_pointer (c++11)
    // is_pointer のヘルパー
    template<typename>
    struct is_pointer_helper:
        public false_type{};
    template<typename T>
    struct is_pointer_helper<T*>:
        public true_type{};
    // is_pointer (c++11)
    // 型が ポインタ型なら true_type から派生し、そうでなければ、false_type から派生     
    template<typename T>
    struct is_pointer:
        public is_pointer_helper<typename remove_cv<T>::type>{};
    // is_pointer_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_lvalue_reference (c++11)
    // 型が 左辺値参照 なら true_type から派生、そうでなければ false_type から派生
    template<typename>
    struct is_lvalue_reference:
        public false_type{};
    template<typename T>
    struct is_lvalue_reference<T&>:
        public true_type{};
    // is_lvalue_reference_v (c++17)
    // (c++11 だと 使用不可の構文の為、未実装)
    
    // is_rvalue_reference (c++11)
    // 型が 右辺値参照 なら true_type から派生し、そうでなければ false_type から派生
    template<typename>
    struct is_rvalue_reference:
        public false_type{};
    template<typename T>
    struct is_rvalue_reference<T&&>:
        public true_type{};
    // is_rvalue_reference_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_member_object_pointer (c++11)
    // is_member_object_pointer のヘルパー
    template<typename>
    struct is_member_object_pointer_helper:
        public false_type{};
    template<typename T, typename U>
    struct is_member_object_pointer_helper<T U::*>:
        public bool_constant<!is_function<T>::value>{};
    // is_member_object_pointer (c++11)
    // 型が メンバ変数型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_member_object_pointer:
        public is_member_object_pointer_helper<typename remove_cv<T>::type>{};
    // is_member_object_pointer_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_member_function_pointer (c++11)
    // is_member_function_pointer のヘルパー
    template<typename>
    struct is_member_function_pointer_helper:
        public false_type{};
    template<typename T, typename U>
    struct is_member_function_pointer_helper<T U::*>:
        public bool_constant<is_function<T>::value>{};
    // is_member_function (c++11)
    // 型が メンバ関数型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_member_function_pointer:
        public is_member_function_pointer_helper<typename remove_cv<T>::type>{};
    // is_member_function_v (c++11)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_enum (c++11)
    // 型が 列挙型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_enum:
        public bool_constant<__is_enum(T)>{};
    // is_enum_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_union (c++11)
    // 型が 共用型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_union:
        public bool_constant<__is_union(T)>{};
    // is_union_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_class (c++11)
    // 型が クラス型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_class:
        public bool_constant<__is_class(T)>{};
    // is_class_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_function (c++11)
    // 型が関数型なら true_type から派生し、そうでなければ false_type から派生
    template<typename>
    struct is_function:
        public false_type{};
    template<typename T, typename... Args>
    struct is_function<T(Args...)>:
        public true_type{};
    // is_function_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    /*
    * 組み合わせた型
    */

    // is_referecne (c++11)
    // 型が 参照型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_reference:
        public bool_constant<is_lvalue_reference<T>::value ||
                             is_rvalue_reference<T>::value>{};
    // is_reference_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_arithmetic (c++11)
    // 型が 算術型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_arithmetic:
        public bool_constant<is_integral<T>::value ||
                             is_floating_point<T>::value>{};
    // is_arithmetic_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_fundamental (c++11)
    // 型が 単純型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_fundamental:
        public bool_constant<is_arithmetic<T>::value ||
                             is_void<T>::value       ||
                             is_null_pointer<T>::value>{};
    // is_fundamental_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_object (c++11)
    // 型が オブジェクト型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_object:
        public bool_constant<is_scalar<T>::value ||
                             is_array<T>::value  ||
                             is_union<T>::value  ||
                             is_class<T>::value>{};
    // is_object_t (c++17)
    // (c++11 だと使用不可の構文の為、未定義)

    // is_scalar (c++11)
    // 型が スカラ型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_scalar:
        public bool_constant<is_arithmetic<T>::value   ||
                             is_enum<T>::value         ||
                             is_pointer<T>::value      ||
                             is_null_pointer<T>::value ||
                             is_member_object_pointer<T>::value>{};
    // is_scalar_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_compound (c++11)
    // 型が 複合型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_compound:
        public bool_constant<!is_fundamental<T>::value>{};
    // is_compound_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_member_pointer (c++11)
    // 型が メンバポインタ型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_member_pointer:
        public bool_constant<is_member_object_pointer<T>::value ||
                             is_member_function_pointer<T>::value>{};
    // is_member_pointer_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    /*
    * 型の特性
    */

    // is_const (c++11)
    // 型が const 修飾型 (volatile 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename>
    struct is_const:
        public false_type{};
    template<typename T>
    struct is_const<T const>:
        public true_type{};
    // is_const_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_volatile (c++11)
    // 型が volatile 修飾型 (const 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename>
    struct is_volatile:
        public false_type{};
    template<typename T>
    struct is_volatile<T volatile>:
        public true_type{};
    // is_volatile_v (c++17)
    // (c++11 では使用不可の構文の為、未実装)
    
    // is_trivial (c++11)
    // 型が トリビアル型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_trivial:
        public bool_constant<__is_trivial(T)>{};
    // is_trivial_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_trivially_copyable (c++11)
    // 型が トリビアルコピー が可能なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_trivially_copyable:
        public bool_constant<__is_trivially_copyable(T)>{};
    // is_trivially_copyable_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_standard_layout (c++11)
    // 型が スタンダードレイアウト型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_standard_layout:
        public bool_constant<__is_standard_layout(T)>{};
    // is_standard_layout_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_pod (c++11)
    // 型が POD型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_pod:
        public bool_constant<__is_pod(T)>{};
    // is_pod_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_literal_type (c++11)(c++17 で非推奨 c++20 で削除)
    // 型が リテラル型 (cv 修飾許容)(配列の場合は次元を除去) なら true_type から派生し、そうでなければ false_type から派生
    // (削除理由: 必要な情報は 定数式で初期化可能か という点の為?)
    template<typename T>
    struct is_literal_type:
        public bool_constant<__is_literal_type(T)>{};
    // is_literal_type_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_empty (c++11)
    // 型が 空のクラス (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_empty:
        public bool_constant<__is_empty(T)>{};
    // is_empty_v (c++17)
    // (c++17 だと使用不可の構文の為、未実装)
    
    // is_polymorphic (c++11)
    // 型が 多相的クラス なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_polymorphic:
        public bool_constant<__is_polymorphic(T)>{};
    // is_polymorphic_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_abstract (c++11)
    // 型が 抽象クラス なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_abstract:
        public bool_constant<__is_abstract(T)>{};
    // is_abstract_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_final (c++14)
    // 型が final指定 されていれば true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_final:
        public bool_constant<__is_final(T)>{};
    // is_final_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // __is_aggregate マクロが定義されているのは g++-7 以上
    #if __GNUC__ >= 7
    // is_aggregate (c++17)
    // 型が 集成体 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_aggregate:
        public bool_constant<__is_aggregate(T)>{};
    // is_aggregate_v (c++17)
    // (c++11 では使用不可の構文の為、未実装)
    #endif

    // is_signed (c++11)
    // is_signed のヘルパー
    template<typename T, bool = is_arithmetic<T>::value>
    struct is_signed_helper:
        public false_type{};
    template<typename T>
    struct is_signed_helper<T, true>:
        public bool_constant<T(-1) < T(0)>{};
    // is_signed (c++11)
    // 型が 符号付き算術型 (cv 修飾許容) なら true_type から派生し、そうでなければ false_type から派生
    // (c++14 から T が算術型出ない場合、 T(0), T(-1) でテンプレート置き換えが発生する為、ヘルパー使用)
    template<typename T>
    struct is_signed:
        public is_signed_helper<T>{};
    // is_signed_t (c++17)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_unsigned (c++11)
    // is_unsigned のヘルパー
    template<typename T, bool = is_arithmetic<T>::value>
    struct is_unsigned_helper:
        public false_type{};
    template<typename T>
    struct is_unsigned_helper<T, true>:
        public bool_constant<T(0) < T(-1)>{};
    // is_unsigned (c++11)
    // 型が 符号なし算術型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_unsigned:
        public is_unsigned_helper<T>{};
    // is_unsigned_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_bounded_array (c++20)
    // is_bounded_array のヘルパー
    template<typename T>
    struct is_bounded_array_helper:
        public bool_constant<(extent<T>::value > 0)>{};
    // is_bounded_array (c++20)
    // 型が 要素数の判明している配列型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_bounded_array:
        public is_bounded_array_helper<T>{};
    // is_bounded_array_v (c++20)
    // (c++11 だと使用不可の構文の為、未実装)
    
    // is_unbounded_array (c++20)
    // is_unbounded_array のヘルパー
    template<typename T>
    struct is_unbounded_array_helper:
        public bool_constant<is_array<T>::value && (extent<T>::value == 0)>{};
    // is_unbounded_array (c++20)
    // 型が 要素数の不明な配列型 なら true_type から派生し、そうでなければ false_type から派生
    template<typename T>
    struct is_unbounded_array:
        public is_unbounded_array_helper<T>{};
    // is_unbounded_array_v (c++20)
    // (c++11 だと使用不可の構文の為、未実装)

    // is_constructible (c++11)
    // 型が コンストラクタ呼び出し が的確なら true_type から派生し、そうでなければ false_type から派生


    /*
    * 型の特性についての問い合わせ
    */

    // extent (c++11)
    // 配列型の i 番目の次元の要素数を取得
    template<typename, unsigned>
    struct extent:
        public integral_constant<size_t, 0>{};
    template<typename T, unsigned U, size_t S>
    struct extent<T[S], U>:
        public integral_constant<size_t, 
                                 (U == 0) ? S : extent<T, U - 1>::value>{};
    template<typename T, unsigned U>
    struct extent<T[], U>:
        public integral_constant<size_t,
                                 (U == 0) ? 0 : extent<T, U - 1>::value>{};
    // extent_v (c++17)
    // (c++11 だと使用不可の構文の為、未実装)

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
   
    /*
    * 参照の変更
    */

    // add_rvalue_reference (c++11)
    // add_rvalue_reference のヘルパー
    template<typename T, bool>
    struct add_rvalue_reference_helper
        {using type = T;};
    template<typename T>
    struct add_rvalue_reference_helper<T, true>
        {using type = T&&;};
    // add_rvalue_reference (c++11)
    // 型に 右辺値参照を付与する
    template<typename T>
    struct add_rvalue_reference:
        public add_rvalue_reference_helper<T, (is_object<T>::value || is_function<T>::value)>{};
};