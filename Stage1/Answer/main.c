#include "Utility.h"

int main()
{
	int arr_i[] = { 0,1,2,3,4,5,5,5,6,8,9 };
	size_t len_i = sizeof(arr_i) / sizeof(arr_i[0]);

	float arr_f[] = { 0,1,2,3,4,5,5,5,6,8,9 };
	size_t len_f = sizeof(arr_f) / sizeof(arr_f[0]);

	char arr_c[] = "01234555689";
	size_t len_c = strlen(arr_c);

	WCHAR arr_w[] = L"01234555689";
	size_t len_w = wcslen(arr_w);

	PCHAR arr_pc[] = { "0123","455","5","5689" };
	size_t len_pc = sizeof(arr_pc) / sizeof(arr_pc[0]);

	PWCHAR arr_pw[] = { L"0123",L"455",L"5",L"5689" };
	size_t len_pw = sizeof(arr_pw) / sizeof(arr_pw[0]);

#define RES(func) printf(STRING_OF( func##---> [%lld]\n ) , func)

	RES(     BinarySearch(int, arr_i, len_i, 5));
	RES(     BinarySearch(float, arr_f, len_f, 5.0));
	RES(     BinarySearch(char, arr_c, len_c, '5'));
	RES(     BinarySearch(WCHAR, arr_w, len_w, L'5'));
	RES(     BinarySearch(PCHAR, arr_pc, len_pc, "5"));
	RES(     BinarySearch(PWCHAR, arr_pw, len_pw, L"5"));

}
