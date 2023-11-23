#pragma once

#define CallCDecl __cdecl
#define CallStd __stdcall
#define CallVector __vectorcall
#define CallDefault CallVector

#define Inline __forceinline

typedef signed char        i8;  static_assert(sizeof(i8)  == 1);
typedef short              i16; static_assert(sizeof(i16) == 2);
typedef int                i32; static_assert(sizeof(i32) == 4);
typedef long long          i64; static_assert(sizeof(i64) == 8);
typedef unsigned char      u8;  static_assert(sizeof(i8)  == 1);
typedef unsigned short     u16; static_assert(sizeof(i16) == 2);
typedef unsigned int       u32; static_assert(sizeof(i32) == 4);
typedef unsigned long long u64; static_assert(sizeof(i64) == 8);

#define stc static_cast
#define dyc dynamic_cast
#define ric reinterpret_cast
#define cnc const_cast