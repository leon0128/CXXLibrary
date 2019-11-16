#pragma once

namespace LEON
{
    // float_round_style
    // 浮動小数点数 の丸めのスタイルに関数列挙値
    enum float_round_style
    {
        round_indeterminate       = -1, // 丸めスタイルが確定しない
        round_toward_zero         = 0,  // 0 に向かって丸められる
        round_to_nearest          = 1,  // 最も近い表現可能な値に丸められる
        round_toward_infinity     = 2,  // 正の無限表現に向かって丸められる
        round_toward_neg_infinity = 3   // 負の無限表現に向かって丸められる
    };

    // float_denorm_style
    // 非正規化数 のサポートに関する情報の為の列挙値
    enum float_denorm_style
    {
        denorm_indeterminate = -1, // 値型が非正規化数を許可するかを判定できない
        denorm_absent        = 0,  // 値型が非正規化数を許可しない
        denorm_present       = 1   // 値型が非正規化数を許可する
    };


    // 特殊化されていないクラスのメンバ変数を定義した基底クラス
    // 必要な時だけ派生クラスで再定義
    class numeric_limits_base
    {
    public:
        // 特殊化されているか
        static constexpr bool is_specialized = false;

        // digits (c++11)
        // 基数 radix において 表示できる桁数を示す
        static constexpr int digits = 0;
        // digits10 (c++11)
        // 10進数において表現できる桁数を示す
        static constexpr int digits10 = 0;
        // max_digits10 (c++11)
        // 浮動小数点数 の10進数表現における正確さを損なわない最大の桁数
        static constexpr int max_digits10 = 0;
        // is_signed (c++11)
        // 型が 符号付き型 なら true そうでなければ false
        static constexpr bool is_signed = false;
        // is_integer (c++11)
        // 型が 整数型 なら true そうでなければ false
        static constexpr bool is_integer = false;
        // is_exact (c++11)
        // 型が 正確な表現 を持つ場合 true そうでなければ false
        static constexpr bool is_exact = false;
        // radix (c++11)
        // digits を表現する基数を示す
        static constexpr int radix = 0;
        // min_exponent (c++11)
        // 浮動小数点数型 において 型の指数下限値を示す
        static constexpr int min_exponent = 0;
        // min_exponent10 (c++11)
        // 浮動小数点数型 において 型の10進指数下限値を示す
        static constexpr int min_exponent10 = 0;
        // max_exponent (c++11)
        // 浮動小数点数型 において 型の指数上限値を示す
        static constexpr int max_exponent = 0;
        // max_exponent10 (c++11)
        // 浮動小数点数型 において 型の10新指数上限値を示す
        static constexpr int max_exponent10 = 0;
        // has_infinity (c++11)
        // 浮動小数点数型 において 型が正の無限表現を持っているか
        static constexpr bool has_infinity = false;
        // has_quiet_NaN (c++11)
        // 浮動小数点数型 において 型がシグナルを投げない NaN を持っているか
        static constexpr bool has_quiet_NaN = false;
        // has_signaling_NaN (c++11)
        // 浮動小数点数型 において 型がシグナルを投げる NaN を持っているか
        static constexpr bool has_signaling_NaN = false;
        // has_denorn (c++11)
        // 浮動小数点数型 において 型の非正規化数のサポート状況を判定
        static constexpr float_denorm_style has_denorm = denorm_absent;
        // has_denorm_loss (c++11)
        // 浮動小数点数型 において 精度の損失が非正規化数によるものかを判定
        static constexpr bool has_denorm_loss = false;
        // is_iec559 (c++11)
        // 浮動小数点数型 において 型が IEC559 (IEEE754) に準拠しているか
        static constexpr bool is_iec559 = false;
        // is_bounded (c++11)
        // 型の値のなす集合が有限かを判定
        static constexpr bool is_bounded = false;
        // is_modulo (c++11)
        // 加算、減算、乗算における数学的な値と、その型の値との間に [max() - min() + 1] を法として
        // 常に合同関係があるか
        static constexpr bool is_modulo = false;
        // traps (c++11)
        // 算術演算によって トラップが発せうする型かどうか
        static constexpr bool traps = false;
        // tinyness_before (c++11)
        // 浮動小数点数型 において 型が丸めが行われる前に小さな値になることを検出できるか
        static constexpr bool tinyness_before = false;
        // round_style (c++11)
        // 浮動小数点数 の丸めスタイルの列挙値
        static constexpr float_round_style round_style = round_toward_zero;
    };

    // 特殊化されていない型
    template<typename T>
    class numeric_limits
    {
    public:
        // min (c++11)
        // 型の最小値取得 (浮動小数点数の場合、非ゼロの正の値の最小値)
        static constexpr T min() noexcept {return T();}
        // max (c++11)
        // 型の最大値取得
        static constexpr T max() noexcept {return T();}
        // lowest (c++11)
        // 型の最小値取得
        static constexpr T lowest() noexcept {return T();}
        // epsilon (c++11)
        // 機械イプシロン を取得する
        static constexpr T epsilon() noexcept {return T();}
        // round_error (c++11)
        // 最大の丸め誤差取得
        static constexpr T round_error() noexcept {return T();}
        // infinity (c++11)
        // 浮動小数点数型 における 正の無限表現を取得
        static constexpr T infinity() noexcept {return T();}
        // quiet_NaN (c++11)
        // 浮動小数点数型 において シグナルを発生させない NaN を取得
        static constexpr T quiet_NaN() noexcept {return T();}
        // signaling_NaN (c++11)
        // 浮動小数点数型 において シグナルを発生させる NaN を取得
        static constexpr T signaling_NaN() noexcept {return T();}
        // denorm_min (c++11)
        // 浮動小数点数型 において 最小の正の非正規化数を取得
        static constexpr T denorm_min() noexcept {return T();}
    };

    
    // template<> class 
};