#include<stdio.h>
#include "sqlist.h"

int main()
{
    SqList *L;
    ElemType e;
    int a[10] = {3, 8, 2, 7, 1, 5, 3, 4, 6, 0};
    InitList(L);
    CreateList(L, a, 10);
    DisplayList(L);
    printf("%d\n", LocateElem(L, 2));
    GetElem(L, e, 3);
    printf("%d\n", e);
    //往第六个位置添加三个元素
    ListInsert(L, 6, 9);
    ListInsert(L, 6, 9);
    ListInsert(L, 6, 9);
    ListInsert(L,1,1);
    DisplayList(L);
    ListDelete(L, 1, e);
    DisplayList(L);
    printf("%d\n", e);
    //应用示例1 删除相同元素值
    delnode1(L,9);
    DisplayList(L);
    //应用示例2 删除相同元素值
    delnode2(L,9);

    //应用示例 基准元素分治算法
    //partition1(L);
    partition2(L);

    DisplayList(L);

    //奇数在偶数前面
    //move1(L);
    move2(L);
    DisplayList(L);

    //销毁线性表
    DestoryList(L);

    return 0;
}