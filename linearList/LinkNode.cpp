#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
typedef int Element;

typedef struct LNode
{
    Element data[Maxsize];
    struct LNode *next;
} LinkNode;

void InitNode(LinkNode *&L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void Destory(LinkNode *L)
{
    LinkNode *p = L, *q;
    while (p->next != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }

    free(p);
}

int main()
{
    LinkNode *L;
    InitNode(L);
    free(L);
}
