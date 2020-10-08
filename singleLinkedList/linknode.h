#ifndef _LINKNODE_H_
#define _LINKNODE_H_

#define MaxSize 50
typedef int Elemtype;
typedef struct LNode
{
    Elemtype data;          //存放元素值
    struct LNode *next;     //指向后继节点
}LinkNode;                  //单链表节点类型

//创建单链表----头插法
void CreateListF(LinkNode *&L, Elemtype a[], int n);

//创建单链表----尾插法
void CreateListR(LinkNode *&L, Elemtype a[], int n);

//初始化单链表
void InitList(LinkNode *&L);

//销毁单链表
void DestoryList(LinkNode *&L);

#endif