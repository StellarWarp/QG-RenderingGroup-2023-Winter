#include "TypedDefineBegin.h"

#define _type_ T

#ifdef INTEGRAL
#define Template up_pow2
T _template_(T n)
{
	if (n == 0) return 1;
	--n;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;
	return ++n;
}
#endif // INTEGRAL



#define Template BinarySearch
uint64_t _template_(T* arr, size_t len, T val)
{
	if (len == 0) return 0;
	if (Cmp(T, val, arr[len - 1]) > 0) return len;//超出范围返回最大索引+1
	if (Cmp(T, val, arr[0]) <= 0) return 0;
	uint64_t mid;//搜索位置
	T mid_val;

	uint64_t a = 0;
	uint64_t b = len - 1;

	while (1)
	{
		mid = (a + b) / 2;
		mid_val = arr[mid];

		if (a == mid) return mid + 1;
		else if (Cmp(T, mid_val, val) < 0) a = mid;
		else if (Cmp(T, mid_val, val) >= 0) b = mid;
	}
}

#include "TypedDefineEnd.h"