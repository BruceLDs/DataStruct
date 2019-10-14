#define  _CRT_SECURE_NO_WARNINGS
#include"List.h"
test(){
	List plist;
	ListInit(&plist);
	ListPushBack(&plist, 1);
	ListPushBack(&plist,2);
	ListPushBack(&plist,3);
	ListPrint(&plist);
	ListPushFront(&plist,  0);
	ListPushFront(&plist, -1);
	ListPushFront(&plist, -2);
	ListPushFront(&plist, -3);
	ListPrint(&plist);
	ListPoBack(&plist);
	ListPrint(&plist);
	ListPopFront(&plist);
	ListPrint(&plist);
	ListNode* p=ListFind(&plist, 13);
	printf("%d\n", p->data);
	ListNode* pos = (ListNode* )(&plist)->head->next;
	ListInsert(&plist, pos, 999);
	ListPrint(&plist);
	ListNode* po= (ListNode*)(&plist)->head->next;
	ListErase(&plist, po);
	ListDestory(&plist);
	ListPrint(&plist);
}
int main()
{
	test();
	return 0;
}