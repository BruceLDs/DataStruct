#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//��������
//�ʺϳ������ӽ���������У�ʱ�临�Ӷ�������O(n)
#if 1
#include<stdio.h>
void InsertSort(int *a,int n){
	int i;
	for (i = 0; i < n - 1; i++){
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && tmp < a[end]){
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

//ϣ������
void ShellSort(int *a, int n){
	int i = 0;
	int gap = n;
	while (gap > 1){
		gap = gap % 3 + 1;
		for (i = 0; i < n - gap; i++)
		{
			if (a[i]>a[i + gap])
				Swap(&a[i], &a[i + gap]);
		}
	}
	gap = 1;
	for (i = 0; i < n - gap; i++)
	{
		if (a[i]>a[i + gap])
			Swap(&a[i], &a[i + gap]);
	}
}
//ѡ������
void SelectSort(int *a, int n){
	//ÿ��ѡһ��������С�ģ��ŵ���Ӧ��λ��
	int i, max, min;
	int begin = 0;
	int end = n - 1;
	while (begin < end){
		max = min = begin;
		for (i = begin; i <= end; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i]>a[max])
				max = i;
		}
		Swap(&a[begin], &a[min]);
		if (max == begin)
			max = min;
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}

//������
void ShiftDown(int *a, int n, int root){
	int child = 2 * root + 1;
	int parent = root;
	while (child < n){
		if (child + 1 < n&&a[child+1]>a[child]){
			child += 1;
		}
		if (a[parent] < a[child]){
			Swap(&a[child], &a[parent]);
		parent = child;
		child = 2 * parent + 1;
	}
		else{
			break;
		}
		
	}
}
void HeapSort(int *a, int n){
	//����
	int i;
	for (i = (n - 2) / 2; i >= 0; --i){
		ShiftDown(a, n, i);
	}
	int end = n - 1;
	while (end){
		Swap(&a[0], &a[end]);
		ShiftDown(a, end, 0);
		end--;
	}
}

//ð������
void BubbleSort(int *a, int n){
	//�ж��Ƿ�����
	int i = 0;
	int j = 0;
	for (; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (a[i] >= a[j])
				Swap(&a[i], &a[j]);
		}
	}
}

//��������
//ʱ�临�Ӷȣ�N*logN
//�ռ临�Ӷȣ��ռ���Ը��ã����ĵݹ������-->logN
//����ȡ��
int getMid(int *a, int left, int right){
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left]){
		if (a[mid] < right){
			return mid;
		}
		else{
			if (a[left]>a[right])
				return left;
			else
				return right;
		}
	}
	else{
		if (a[mid] > right){
			return mid;
		}
		else{
			if (a[left]>a[right])
				return right;
			else
				return left;
		}
	}
}
int  PartSort1(int *a, int left, int right)//����һ������
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	int start = left;
	//Ѱ�Ҵ��ֵ���н���
	while(left < right){
		//���ұ���С��key��ֵ
		while (left < right&&a[right] >= key)
			--right;
		//������Ҵ���key��ֵ
		while (left < right&&a[left] <= key)
			++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[start], &a[left]);
	return left;
}
//�ڿӷ�
int  PartSort2(int *a, int left, int right)//����һ������
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	while (left < right){
		//���ұ߱���С��key��ֵ
		while (left < right&&a[right] >= key)
			--right;
		//���
		Swap(&a[left], &a[right]);
		//������Ҵ���key��ֵ
		while (left < right&&a[left] <= key)
			++left;
		//���
		Swap(&a[left], &a[right]);
	}
	return left;
}

int  PartSort3(int *a, int left, int right)//����һ������
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int prev = left;
	int cur = left + 1;
	int key = a[left];
	while (cur < right){
		//�����һ��С��key��λ������һ��С��key��λ�ò�����
		//˵���м��д���key��ֵ�����н�������-->��С-->ǰ
		if (a[cur] < key&&++prev != cur){
			Swap(&a[prev], &a[cur]);
		}
		++cur;//31,16,75,15, 8, 45-->
	}
	//��������
	Swap(&a[prev], &a[left]);
	return prev;
}
void QuickSort(int *a, int left, int right){
	if (left >= right)
		return;
	if (right - left + 1 < 5){
		InsertSort(a + left, right - left + 1);
	}
	else{
		int mid = PartSort3(a, left, right);
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
}

//�ǵݹ��������
//void QuickSort(int *a, int left, int right){
//	if (left >= right)
//		return;
//	Stack st;
//	StackInit(&st);
//	if (left < right){
//		StackPush(&st, right);
//		StackPush(&st, left);
//	}
//	while (StackEmpty(&st) == 0){
//		int begin = StackTop(&st);
//		StackPop(&st);
//		int end = StackTop(&st);
//		StackPop(&st);
//		int mid = PartSort(a, begin, end);
//		if (begin < mid - 1){
//			StackPush(&st, mid-1);
//			StackPush(&st, begin);
//		}
//		if (mid + 1 < end){
//			StackPush(&st, end);
//			StackPush(&st, mid+1);
//		}
//	}
//}
//�鲢����
void _MergeSort(int *a, int left, int right, int *tmp)
{
	//����ֻʣһ��Ԫ�أ�����Ҫ�ֽ�͹鲢
	if (left >= right)
		return;
	//�ֽ�
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//�鲢
	int begin1 = left, begin2 = mid+1,
		end1 = mid, end2 = right;//begin1~end2   ->left~right
	int tmpindex = begin1;
	while (begin1 <= end1&&begin2 <= end2){
		if (a[begin1] <= a[begin2]){
			tmp[tmpindex++] = a[begin1++];
		}
		else{
			tmp[tmpindex++] = a[begin2++];
		}
	}
	while (begin1 <= end1){
		tmp[tmpindex++] = a[begin1++];
	}
	while (begin2 <= end2){
		tmp[tmpindex++] = a[begin2++];
	}
	//������ԭ�������Ӧ�ռ�
	memcpy(a + left, tmp + left, (right-left + 1)*sizeof(int));
}
void MergeSort(int *a, int n){
	int *tmp = (int *)malloc(n*sizeof(int));
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//��������
void CountSort(int *a, int n){

	//��Χ�� 0 ~ n
	//��Χ����Сֵ ~ ���ֵ
	int min = a[0], max = a[0];
	int i; 
	for (i = 1; i < n; i++){
		if (a[i] < min)
			min = a[i];
		if (a[i]>max)
			max = a[i];
	}
	int range = max - min + 1;
	int *CountArr = (int *)malloc(sizeof(int)* range);
	memset(CountArr, 0, sizeof(int)* range);
	//����
	for (i = 0; i < n; ++i){
		CountArr[a[i] - min]++;
	}
	//����
	int index = 0;
	for (i = 0; i < range; ++i){
		while (CountArr[i]--)
		a[index++] = i + min;
	}
}
void Print(int *a, int n){
	for (int j = 0; j < n; j++){
		printf("%d ", a[j]);
	}
	printf("\n");
}
int main()
{
int arr[] = { 31,16,7,1, 8, 45, 2, 4,  3, 6, 17 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Print(arr, n);
	//InsertSort(arr, n);
	//Print(arr, n);
    //ShellSort(arr, n);    
	//SelectSort(arr, n);
	//HeapSort(arr, n);
	//BubbleSort(arr, n);
	//QuickSort(arr, 0, n - 1);
	//MergeSort(arr, n);
	CountSort(arr, n);
	Print(arr, n);
	return 0;
}
#endif