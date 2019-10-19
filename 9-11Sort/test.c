#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//插入排序
//适合场景：接近有序的序列，时间复杂度趋近于O(n)
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

//希尔排序
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
//选择排序
void SelectSort(int *a, int n){
	//每次选一个最大的最小的，放到相应的位置
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

//堆排序
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
	//建堆
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

//冒泡排序
void BubbleSort(int *a, int n){
	//判断是否有序
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

//快速排序
//时间复杂度：N*logN
//空间复杂度：空间可以复用，最大的递归调用链-->logN
//三数取中
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
int  PartSort1(int *a, int left, int right)//快速一次排序
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	int start = left;
	//寻找大的值进行交换
	while(left < right){
		//从右边找小于key的值
		while (left < right&&a[right] >= key)
			--right;
		//从左边找大于key的值
		while (left < right&&a[left] <= key)
			++left;
		Swap(&a[left], &a[right]);
	}
	Swap(&a[start], &a[left]);
	return left;
}
//挖坑法
int  PartSort2(int *a, int left, int right)//快速一次排序
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);
	int key = a[left];
	while (left < right){
		//从右边边找小于key的值
		while (left < right&&a[right] >= key)
			--right;
		//填坑
		Swap(&a[left], &a[right]);
		//从左边找大于key的值
		while (left < right&&a[left] <= key)
			++left;
		//填坑
		Swap(&a[left], &a[right]);
	}
	return left;
}

int  PartSort3(int *a, int left, int right)//快速一次排序
{
	int mid = getMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int prev = left;
	int cur = left + 1;
	int key = a[left];
	while (cur < right){
		//如果下一个小于key的位置于上一个小于key的位置不连续
		//说明中间有大于key的值，进行交换，大-->后，小-->前
		if (a[cur] < key&&++prev != cur){
			Swap(&a[prev], &a[cur]);
		}
		++cur;//31,16,75,15, 8, 45-->
	}
	//遍历结束
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

//非递归快速排序
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
//归并排序
void _MergeSort(int *a, int left, int right, int *tmp)
{
	//区间只剩一个元素，不需要分解和归并
	if (left >= right)
		return;
	//分解
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//归并
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
	//拷贝到原有数组对应空间
	memcpy(a + left, tmp + left, (right-left + 1)*sizeof(int));
}
void MergeSort(int *a, int n){
	int *tmp = (int *)malloc(n*sizeof(int));
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//计数排序
void CountSort(int *a, int n){

	//范围： 0 ~ n
	//范围：最小值 ~ 最大值
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
	//计数
	for (i = 0; i < n; ++i){
		CountArr[a[i] - min]++;
	}
	//排序
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