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
    ListInsert(L, 6, 6);
    DisplayList(L);
    ListDelete(L, 1, e);
    DisplayList(L);
    printf("%d\n", e);
    DestoryList(L);

    return 0;
}