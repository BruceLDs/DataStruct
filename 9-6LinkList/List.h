#ifndef LIST_H_
// 带头双向循环链表增删查改实现
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct ListNode
{
	DataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;
typedef struct List
{
	ListNode* head;
}List;
ListNode *ListNodeCreat( DataType x);
void ListInit(List* plist);
void ListDestory(List* plist);
void ListPushBack(List* plist, DataType x);
void ListPushFront(List* plist, DataType x);
void ListPoBack(List* plist);//尾删
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, DataType x);
void ListInsert(List* plist, ListNode* pos, DataType x);// 在pos的前面进行插入
void ListErase(List* plist, ListNode* pos);// 删除pos位置的节点
void ListPrint(List* plist);
#endif