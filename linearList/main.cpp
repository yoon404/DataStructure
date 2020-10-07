#include<stdio.h>
#include "sqlist.h"

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
    //往第六个位置添加三个元素
    ListInsert(L, 6, 6);
    ListInsert(L, 6, 6);
    ListInsert(L, 6, 6);
    DisplayList(L);
    ListDelete(L, 1, e);
    DisplayList(L);
    printf("%d\n", e);
    //应用示例1 删除相同元素值
    delnode1(L,6);
    DisplayList(L);
    //应用示例2 删除相同元素值
    delnode2(L,6);
    DisplayList(L);
    DestoryList(L);

    return 0;
}