#ifndef LIST_H_
// ��ͷ˫��ѭ��������ɾ���ʵ��
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
void ListPoBack(List* plist);//βɾ
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, DataType x);
void ListInsert(List* plist, ListNode* pos, DataType x);// ��pos��ǰ����в���
void ListErase(List* plist, ListNode* pos);// ɾ��posλ�õĽڵ�
void ListPrint(List* plist);
#endif