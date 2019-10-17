#include<stdio.h>
#include<assert.h>
#include<malloc.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int top; // Õ»¶¥
	int capacity; // ÈÝÁ¿
}Stack;
void StackInit(Stack* ps);
void CapacityCheak(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);
void StackPrint(Stack* ps);
void TestStack();