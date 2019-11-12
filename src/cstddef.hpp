#pragma once

#define DEFAULT_PTRDIFF_T long
#define DEFAULT_SIZE_T    long

namespace LEON
{
    // ptrdiff_t
    // 2 つのポインタの減算を示す結果を示す型
    // 処理系定義の実装方法が解らないため、一時的に DEFAULT_PTRDIFF_T を定義
    using ptrdiff_t = DEFAULT_PTRDIFF_T;
    
    // size_t
    
};