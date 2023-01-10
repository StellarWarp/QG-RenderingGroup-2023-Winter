#pragma once

void UseExceptionDetection_ReturnVoid(int any)
{
	//Debug check , this code will not appear in release mode
	CHECK(
		//detect exception and print error message
		//ETNR often use with marco, function will not stop here
		if (any < 0) ETNR(Error, "negative number");
	);
	CHECK(
		//ET has a return, function stops here
		if (any > 10) ET(OverFlow, "number too large");
	);
	//other code
}
int UseExceptionDetection_WithReturnValue(int any)
{
	CHECK(
		if (any < 0) ET(Error, "negative number", -1);
	);
	//other code
	return 0;
}
//Status can be used to trace function call
//but not necessarily to use, you can make function return void
Status UseExceptionDetection_WithTrace(int any)
{
	//Debug check , this code will not appear in release mode
	CHECK(
		if (any < 0) ETS(Error, "negative number");
	);
	//other code
	return OK;
}
void HowToUseCodeInCommon_h()
{
	//MALLOC and REALLOC
	int* array = MALLOC(int, 10);
	array = REALLOC(int, array, 20);

	//Execption catch
	///write exception detect code helps you to find bugs
	UseExceptionDetection_ReturnVoid(20);
	UseExceptionDetection_WithReturnValue(-1);
	//you can trace exception like this
	EC(UseExceptionDetection_WithTrace(-1));

	//string transfrom
	printf(STRING_OF(array));
	printf("\n");



	/*
	* magic field
	*/
	///connect code with MACRO_CAT
	//array[0]=12;
	MACRO_CAT(a, r, r, a, y)[0] = MACRO_CAT(1, 2);

	///over load macro by the num of parameters
#define MAX_2(a,b) (a>b?a:b)
#define MAX_3(a,b,c) MAX_2(a,MAX_2(b,c))
#define MAX_4(a,b,c,d) MAX_2(MAX_2(a,b),MAX_2(c,d))
#define MAX(...) VA_MACRO(MAX,__VA_ARGS__)

	printf("%d\n", MAX(1, 2));
	printf("%d\n", MAX(1, 2, 3));
	printf("%d\n", MAX(1, 2, 3, 4));

	free(array);
}