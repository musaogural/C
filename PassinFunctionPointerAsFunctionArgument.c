
#include <stdio.h>


typedef int(*functionPointer)(int, int);


int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}



int operation(functionPointer funcP, int a, int b)
{
	(*funcP)(a, b);
	//funcP(a, b);
}

int main()
{
	int a;
	int b;

	int cmd;
	//0 --> a+b
	//1 --> a-b
	//2 --> a*b

	a = 10;
	b = 15;
	cmd = 2;

	functionPointer funcPtrArr[] = { add, sub, mul };

	int result = operation(funcPtrArr[cmd], a, b);
	printf("Result = %d\n", result);


}