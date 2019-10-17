#define  _CRT_SECURE_NO_WARNINGS
#include"Queue.h"
void QueueInit(Queue* pq)
{
	pq->_front = pq->_rear = NewQueueNode(0);
	pq->_front->_next = NULL;
}
void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur){
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}
QueueNode* NewQueueNode(QUDataType x)
{
	QueueNode* NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->_data = x;
	NewNode->_next = NULL;
	return NewNode;
}
void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* NewNode = NewQueueNode(x);
	pq->_rear->_next = NewNode;
	pq->_rear = NewNode;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* next = pq->_front->_next;
	pq->_front->_next = next->_next;
}
QUDataType QueueFront(Queue* pq)
{
	return pq->_front->_next->_data;
}
QUDataType QueueBack(Queue* pq)
{
	return  pq->_rear->_data;
}
int QueueEmpty(Queue* pq)
{
	return pq->_front==pq->_rear?1:0;
}
int QueueSize(Queue* pq)
{
	QueueNode* cur=pq->_front;
	int i=0;
	while(cur!=pq->_rear){
		i++;
		cur=cur->_next;
}
	return i;
}
void QueuePrint(Queue* pq){
	assert(pq);
	QueueNode* cur = pq->_front->_next;
	printf("front -> ");
	while (cur){
		printf("%d -> ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
void TestQueue()
{
	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 2);
	QueuePush(&pq, 3);
	QueuePush(&pq, 4);
	QueuePush(&pq, 5);
	QueuePush(&pq, 6);
	QueuePrint(&pq);
	QueuePop(&pq);
	QueuePrint(&pq);
	printf("%d\n", QueueFront(&pq));
	printf("%d\n",QueueBack(&pq));
	printf("%d\n", QueueEmpty(&pq));
	printf("%d\n", QueueSize(&pq));
	QueueDestory(&pq);
}