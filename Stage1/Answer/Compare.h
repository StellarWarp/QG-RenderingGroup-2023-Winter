#pragma once
#include "Common.h"
#include "TypedDefineBegin.h"

#define Template Cmp
#define T char
#include "CompareTemplate.h"
#define T WCHAR
#include "CompareTemplate.h"
#define T int
#include "CompareTemplate.h"
#define T uint32_t
#include "CompareTemplate.h"
#define T int64_t
#include "CompareTemplate.h"
#define T uint64_t
#include "CompareTemplate.h"
#define T size_t
#include "CompareTemplate.h"
#define T float
#include "CompareTemplate.h"
#define T double
#include "CompareTemplate.h"
#undef T

#define Cmp_PWCHAR wcscmp
#define Cmp_PCHAR strcmp

//a > b    1
//a < b   -1
//a==b    0
#define Cmp(type , a , b) _TypedVar_(Cmp,type)(a, b)
#include "TypedDefineEnd.h"