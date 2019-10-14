#define  _CRT_SECURE_NO_WARNINGS
#include"List.h"
ListNode *ListNodeCreat(DataType x){
	ListNode* NewNode = (ListNode *)malloc(sizeof(ListNode));
	NewNode->data = x;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
}
void ListInit(List* plist)
{
	plist->head = ListNodeCreat(0);
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
}
void ListPushBack(List* plist, DataType x){
	ListNode* NewNode = ListNodeCreat(x);
	ListNode *TailNode = plist->head->prev;
	TailNode->next = NewNode;
	NewNode->prev = TailNode;
	NewNode->next = plist ->head;
	plist->head->prev = NewNode;
}
void ListPushFront(List* plist, DataType x)
{
	ListNode* NewNode = ListNodeCreat(x);
	ListNode* next = plist->head->next;
    plist->head->next=NewNode;
	NewNode->next=next;
	NewNode->prev = plist->head;
	next->prev = NewNode;
}
void ListPoBack(List* plist)
{
	assert(plist);
	if (plist->head->next != plist->head){
		ListNode* TailNode = plist->head->prev;
		ListNode* prev = TailNode->prev;
		prev->next = plist->head;
		plist->head->prev = prev;
		free(TailNode);
		TailNode = NULL;
	}
}
void ListPopFront(List* plist)
{
	assert(plist->head);
	if (plist->head->next != plist->head){
		ListNode* PopNode = plist->head->next;
		ListNode* next = PopNode->next;
		plist->head->next = next;
		next->prev = plist->head->prev;
		free(PopNode);
		PopNode = NULL;
	}
}
ListNode* ListFind(List* plist, DataType x)
{
	assert(plist->head);
	ListNode* cur = plist->head;
	while (cur->next != plist->head&&x > 0){
		cur = cur->next;
		x--;
	}
	if (x==0)
		return cur;
	return plist->head;//未找到返回头节点
}
void ListInsert(List* plist,ListNode* pos, DataType x)
{
	assert(plist->head);
	ListNode* cur = plist->head->next;
	ListNode* der = plist->head;
	while (cur->next != plist->head){
		if (cur == pos)
			break;
		cur = cur->next;
		der = der->next;
	}
		ListNode* NewNode = ListNodeCreat(x);
		der->next = NewNode;
		NewNode->next = pos;
		NewNode->prev = der;
		pos->prev = NewNode;
}
void ListErase(List* plist, ListNode* pos)
{
	assert(plist->head);
	ListNode* cur = plist->head->next;
	ListNode* der = plist->head;
	while (cur->next != plist->head){
		if (cur == pos)
			break;
		cur = cur->next;
		der = der->next;
	}
		ListNode* tmp = pos->next;
		der->next = tmp;
		tmp->prev = der;
		free(cur);
		cur = NULL;
}
void ListDestory(List* plist)
{
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
}
void ListPrint(List* plist)
{
	ListNode* p = plist->head->next ;
	assert(plist);
	while (p != plist->head){
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("\n");
}