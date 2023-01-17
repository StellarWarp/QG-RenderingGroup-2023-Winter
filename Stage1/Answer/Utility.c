#include "Utility.h"

#define INTEGRAL
#define T char
#include "UtilityCore.h"
#define T WCHAR
#include "UtilityCore.h"
#define T int
#include "UtilityCore.h"
#define T int64_t
#include "UtilityCore.h"
#define T size_t
#include "UtilityCore.h"
#undef INTEGRAL

#define T float
#include "UtilityCore.h"
#define T double
#include "UtilityCore.h"

#define T PCHAR
#include "UtilityCore.h"
#define T PWCHAR
#include "UtilityCore.h"



