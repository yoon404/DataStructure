#include "linknode.h"
#include <stdio.h>
#include <stdlib.h>

//创建单链表----头插法
void CreateListF(LinkNode *&L, ElemType a[], int n)
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
void CreateListR(LinkNode *&L, ElemType a[], int n)
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

//判断线性表是否为空表
bool ListEmpty(LinkNode *L)
{
    return L->next == NULL;
}

//求线性表的长度
int ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p = L;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    return (n);
}

//输出线性表
void DispList(LinkNode *L)
{
    LinkNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//求线性表的某个数据元素值
bool GetElem(LinkNode *L, int i, ElemType &e)
{
    int j = 1;
    LinkNode *p = L->next;
    if (i <= 0)
        return false;

    while (p != NULL)
    {
        if (i == j)
        {
            e = p->data;
            return true;
        }
        p = p->next;
        j++;
    }
    return false;
}

//按元素值查找
int LocateElem(LinkNode *L, ElemType e)
{
    int i = 1;
    LinkNode *p = L->next;
    while (p != NULL)
    {
        if (p->data == e)
        {
            return i;
        }
        i++;
        p = p->next;
    }
    return 0;
}

//往第i个位置插入数据元素
bool ListInsert(LinkNode *&L, int i, ElemType e)
{
    int j = 1;
    if (i <= 0)
        return false;
    LinkNode *p = L, *s;
    while (p != NULL)
    {
        if (i == j)
        {
            s = (LinkNode *)malloc(sizeof(LinkNode));
            s->data = e;
            s->next = p->next;
            p->next = s;
            return true;
        }
        p = p->next;
        j++;
    }
    return false;
}

//删除数据元素
bool ListDelete(LinkNode *&L, int i, ElemType &e)
{
    LinkNode *p = L, *q = p->next;
    int j = 1;
    while (q != NULL)
    {
        if (i == j)
        {
            e = q->data;
            p->next = q->next;
            free(q);
            return true;
        }
        p = q;
        q = p->next;
        j++;
    }
    return false;
}

//SingleLinkedList Application:有一个带头结点的单链表L，将其拆分为两个带头结点的单链表L1和L2
void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2)
{
    LinkNode *p = L->next, *q, *r1;
    L1 = L;
    r1 = L1;
    L2 = (LinkNode *)malloc(sizeof(LinkNode));
    L2->next = NULL;
    while (p != NULL)
    {
        r1->next = p;
        r1 = p;
        p = p->next;
        q = p->next;
        p->next = L2->next;
        L2->next = p;
        p = q;
    }
    r1->next = NULL;
}
