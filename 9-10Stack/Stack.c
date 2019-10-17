#define  _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->top = 0; // 栈顶
	ps->capacity = 0; // 容量

}
void StackDestory(Stack* ps){
	assert(ps);
	ps->top = 0;
	ps = NULL;
	free(ps);
}
void CapacityCheak(Stack* ps){
	if (ps->top == ps->capacity){
		size_t newCapacity = (ps->capacity == 0 ? sizeof(STDataType) : 2 * ps->capacity);
		ps->_a = (STDataType *)realloc(ps->_a, newCapacity * sizeof(STDataType));
		assert(ps->_a);
		ps->capacity = newCapacity;
	}
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	CapacityCheak(ps);
	ps->_a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps&&ps->top);
	ps->top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps&&ps->top);
	return ps->_a[ps->top - 1];
}
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0){
		return 1;
	}
	return 0;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top - 1;
}
void StackPrint(Stack* ps ){
	int i = ps->top;
	while (--i>=0){
		printf("%d ", ps->_a[i]);
	}
	printf("\n");
}
void TestStack()
{
	Stack s;
	//初始化
	StackInit(&s);
	//入栈
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPrint(&s);
	//出栈
	StackPop(&s);
	StackPrint(&s);
	StackPop(&s);
	StackPrint(&s);
	//销毁
	StackDestory(&s);
	StackPrint(&s);

}