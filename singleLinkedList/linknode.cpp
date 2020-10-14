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
    return i;
}
