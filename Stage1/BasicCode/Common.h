#pragma once
//常用头文件
#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include <stdbool.h>
#include <wtypes.h>

#include <memory.h>
#include <malloc.h>

#include "Macro.h"

#define Foreach(iter, container, containerType, dataType)\
for(dataType* iter = containerType##Begin(dataType,container);\
iter != containerType##End(dataType,container)\
; iter = containerType##Forward(dataType,container, iter))

typedef enum Status
{
	Error = 0,
	OK = 1,
	Break = 0,
	Continue = 1,
	OverFlow,
	OutOfRange
}Status;

//异常处理
#pragma warning(error:4047)
#pragma warning(error:4033)
#pragma warning(error:4098)
#pragma warning(error:4013)
#pragma warning(error:4002)
#pragma warning(error:4113)
#pragma warning(error:4716)

#ifdef _DEBUG
//Exception Process
#define EP(excpetion)\
if (status == excpetion)\
{\
	if(what)\
		printf(STRING_OF(Exception : [#excpetion] %s.From function[%s] in %s line[%d]\n), what, func, file, line);\
	else\
		printf(STRING_OF(Exception : [#excpetion].From function[%s] in %s line[%d]\n), func, file, line);\
}

inline void ExceptionCall(Status status, const char* what, const char* func, const char* file, int line)
{
	HANDLE hand_out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hand_out, FOREGROUND_RED);
	if (status == OK) return;
	EP(Error);
	EP(OverFlow);
	EP(OutOfRange);
	SetConsoleTextAttribute(hand_out, 
		(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED));
#if defined(EXCEPTION_INSTANT_EXIT)
	exit(status);
#endif // defined(EXCEPTION_INSTANT_EXIT)
}

//Exception Catch
#define EC(function_call) ExceptionCall(function_call,NULL,STRING_OF(function_call),__FILE__,__LINE__)
//Exception Throw Standard
#define ETS(status,what) do{ExceptionCall(status,what,__FUNCTION__,__FILE__,__LINE__); return status;}while(0)
//Exception Throw
#define ET(status,what,ret) do{ExceptionCall(status,what,__FUNCTION__,__FILE__,__LINE__); return ret;}while(0)
//Exception Throw No Return
#define ETNR(status,what) ExceptionCall(status,what,__FUNCTION__,__FILE__,__LINE__)

#define CHECK(x) x

#else
#define EC(function_call) function_call
#define ETS(status,what) ((void)0)
#define ET(status,what,ret) ((void)0)
#define NULLCHECK(val) ((void)0)
#define CHECK(x) ((void)0)

#endif // _DEBUG

