//
// Created by MrBun on 2021/7/14.
//
#include<iostream>
#define MaxSize 50
#define ElemType int
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;
void initQueue(LinkQueue &Q)
{
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=nullptr;
}
bool isEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return true;
    else
        return false;;
}
void EnQueue(LinkQueue &Q,ElemType x)
{
    LinkNode *s=(LinkNode*) malloc(sizeof(LinkNode));
    s->data=x;s->next= nullptr;
    Q.rear->next=s;
    Q.rear=s;
}
bool DeQueue(LinkQueue &Q,ElemType &x)
{
    if(Q.rear==Q.front)
        return false;
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(p==Q.rear)5
        Q.rear=Q.front;
    free(p);
    return true;
}
int main()
{
    int data;
    LinkQueue Q;
    initQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);
    DeQueue(Q,data);
    DeQueue(Q,data);
    DeQueue(Q,data);
    DeQueue(Q,data);
}
