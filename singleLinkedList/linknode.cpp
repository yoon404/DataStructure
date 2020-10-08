#include "linknode.h"
#include <stdio.h>
#include <stdlib.h>

//创建单链表----头插法
void CreateListF(LinkNode *&L, Elemtype a[], int n)
{
    LinkNode *p;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++)
    {
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
}

//创建单链表----尾插法
void CreateListR(LinkNode *&L, Elemtype a[], int n)
{
    LinkNode *p, *r;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;
    for (int i = 0; i < n; i++)
    {
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = a[i];
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

//初始化单链表
void InitList(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

//销毁单链表
void DestoryList(LinkNode *&L)
{
    LinkNode *p = L->next, *pre = L;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}