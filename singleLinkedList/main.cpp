#include <stdio.h>
#include <stdlib.h>
#include "linknode.h"

int main()
{
    LinkNode *L;
    ElemType e;
    int a[10] = {3, 8, 2, 7, 1, 5, 3, 4, 6, 0};
    InitList(L);
    CreateListF(L, a, 10);
    DispList(L);
    printf("------------\n");

    if (GetElem(L, 2, e))
        printf("第2个元素为%d\n", e);
    else
    {
        printf("序号错误！\n");
        printf("------------\n");
    }
    printf("找到的为1的元素序号为：%d\n", LocateElem(L, 1));
    printf("------------\n");
    if (ListInsert(L, 1, 10))
    {
        DispList(L);
        printf("------------\n");
    }
    else
    {
        printf("插入错误！请重试！\n");
        printf("------------\n");
    }
    if (ListDelete(L, 11, e))
    {
        printf("删除的元素为%d\n", e);
        DispList(L);
        printf("------------\n");
    }
    else
    {
        printf("删除元素错误！\n");
        printf("------------\n");
    }

    DestoryList(L);
    return 0;
}