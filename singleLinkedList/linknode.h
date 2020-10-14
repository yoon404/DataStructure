#ifndef _LINKNODE_H_
#define _LINKNODE_H_

#define MaxSize 50
typedef int ElemType;
typedef struct LNode
{
    ElemType data;          //存放元素值
    struct LNode *next;     //指向后继节点
}LinkNode;                  //单链表节点类型

//创建单链表----头插法
void CreateListF(LinkNode *&L, ElemType a[], int n);

//创建单链表----尾插法
void CreateListR(LinkNode *&L, ElemType a[], int n);

//初始化单链表
void InitList(LinkNode *&L);

//销毁单链表
void DestoryList(LinkNode *&L);

//判断线性表是否为空表
bool ListEmpty(LinkNode *L);

//求线性表的长度
int ListLength(LinkNode *L);

//输出线性表
void DispList(LinkNode *L);

//求线性表的某个数据元素值
bool GetElem(LinkNode *L, int i, ElemType &e);

//按元素值查找
int LocateElem(LinkNode *L,ElemType e);

#endif