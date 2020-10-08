#include "sqlist.h"
#include <stdio.h>
#include <stdlib.h>

//1.创建顺序表
void CreateList(SqList *&L, ElemType a[], int n)
{
    int i = 0, k = 0;
    L = (SqList *)malloc(sizeof(SqList));
    while (i < n)
    {
        L->data[k] = a[i];
        i++;
        k++;
    }
    L->length = k;
}

//2.初始化顺序表
void InitList(SqList *&L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

//3.销毁线性表
void DestoryList(SqList *&L)
{
    free(L);
}

//4.求线性表的长度
int ListLength(SqList *L)
{
    return L->length;
}

//5.输出线性表
void DisplayList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

//6.求线性表中的某个数据元素值
bool GetElem(SqList *L, ElemType &a, int i)
{
    if (i < 1 || i > L->length)
        return false;
    a = L->data[i - 1];
    return true;
}

//7.按元素值查找
int LocateElem(SqList *L, ElemType e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

//8.插入数据元素
bool ListInsert(SqList *&L, int i, ElemType e)
{
    int j;
    if (i < 1 || i > L->length + 1)
        return false;
    L->length++;
    for (j = L->length; j > i - 1; j--)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[j] = e;
    return true;
}

//9.删除数据元素
bool ListDelete(SqList *&L, int i, ElemType &e)
{
    int j;
    if (i < 1 || i > L->length)
        return false;
    e = L->data[--i];
    for (j = i; j < L->length; j++)
    {
        L->data[j] = L->data[j + 1];
    }
    L->length--;
    return true;
}

//顺序表的应用示例1 删除所有值等于x的元素，时间复杂度为O(n),空间复杂度为O(1)
void delnode1(SqList *&L, ElemType x)
{
    int k = 0, i; //k记录不等于x的元素个数，即要插入到L中的元素个数
    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] != x)
        { //如果data值不等于x
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

//顺序表的应用示例2 删除所有值等于x的元素，时间复杂度为O(n),空间复杂度为O(1)
void delnode2(SqList *&L, ElemType x)
{
    int k = 0, i;
    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] == x)
        {
            k++;
        }
        else
        {
            L->data[i - k] = L->data[i];
        }
    }
    L->length -= k;
}

/*顺序表的应用示例：顺序表L，以第一个元素为基准
将所有小于等于它的元素移动到该基准的前面，将所有大于他的元素移动到后面(分治)*/
void partition1(SqList *&L)
{
    ElemType pivot = L->data[0];
    int i = 0, j = L->length - 1;
    while (i < j)
    {
        while (i < j && L->data[j] > pivot)
        {
            j--;
        }
        while (i < j && L->data[i] <= pivot)
        {
            i++;
        }
        swap(L->data[i], L->data[j]);
    }
    swap(L->data[0], L->data[i]);
}

/*顺序表的应用示例：顺序表L，以第一个元素为基准
将所有小于等于它的元素移动到该基准的前面，将所有大于他的元素移动到后面(分治)*/
void partition2(SqList *&L)
{
    int i = 0, j = L->length - 1;
    ElemType pivot = L->data[0]; //以data[0]为基准
    while (i < j)                //从顺序表两端交替向中间扫描，直到i=j为止
    {
        while (i < j && L->data[j] > pivot)
        {
            j--; //从右向左扫描，找一个小于等于pivot的data[j]
        }
        if (i < j)
            L->data[i] = L->data[j]; //找到这样的data[j],放入data[i]处
        while (i < j && L->data[i] <= pivot)
        {
            i++; //从左向右扫描，找一个大于pivot的data[i]
        }
        if (i < j)
            L->data[j] = L->data[i]; //找到这样的data[i],放入data[j]处
    }
    L->data[i] = pivot;
}

//顺序表的应用示例 所有奇数移动到偶数前面
void move1(SqList *&L)
{
    int i = 0, j = L->length - 1;
    while (i < j)
    {
        while (i < j && L->data[j] % 2 == 0)
        {
            j--;
        }
        while (i < j && L->data[i] % 2 == 1)
        {
            i++;
        }
        if (i < j)
        {
            swap(L->data[i], L->data[j]);
        }
    }
}

//顺序表的应用示例 所有奇数移动到偶数前面
void move2(SqList *&L)
{
    int i = -1, j;
    for (j = 0; j < L->length; j++)
    {
        if (L->data[j] % 2 == 1)
        {
            i++;
            if (i != j)
                swap(L->data[i], L->data[j]);
        }
    }
}

//交换函数
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
