#include <stdio.h>
#include <stdlib.h>
#define Maxsize 50
typedef int ElemType;

typedef struct
{
    ElemType data[Maxsize];
    int length;
} SqList;

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

int main()
{
    SqList *L;
    ElemType e;
    int a[5] = {1, 2, 3, 4, 5};
    InitList(L);
    CreateList(L, a, 5);
    DisplayList(L);
    printf("%d\n", LocateElem(L, 2));
    GetElem(L, e, 3);
    printf("%d\n", e);
    ListInsert(L, 6, 6);
    DisplayList(L);
    ListDelete(L, 1, e);
    DisplayList(L);
    printf("%d\n", e);
    DestoryList(L);

    return 0;
}
