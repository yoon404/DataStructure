#include<stdio.h>
#include<stdlib.h>
#include "linknode.h"

int main(){
    LinkNode *L;
    ElemType e;
    int a[10] = {3, 8, 2, 7, 1, 5, 3, 4, 6, 0};
    InitList(L);
    CreateListF(L,a,10);
    DispList(L);
    DestoryList(L);

    return 0;
}