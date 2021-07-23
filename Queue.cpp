//
// Created by MrBun on 2021/7/14.
//
#include<iostream>
#define MaxSize 50
#define ElemType int
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;
//初始化队列
void initQueue(SqQueue &S)
{
    S.rear=S.front=0;
}
//判断队列是否为空队列
bool isEmpty(SqQueue S)
{
    if(S.rear==S.front)
        return true;
    else
        return false;
}
//入队
bool EnQueue(SqQueue &S,ElemType x)
{
    if((S.rear+1)%MaxSize==S.front)
        return false;
    S.data[S.rear++%MaxSize]=x;
    return true;
}
//出队
bool DeQueue(SqQueue &S,ElemType &x)
{
    if(S.rear==S.front)
        return false;
    x=S.data[S.front++%MaxSize];
    return true;
}
int main()
{
    int data;
    SqQueue S;
    initQueue(S);
    EnQueue(S,1);
    EnQueue(S,2);
    DeQueue(S,data);
    EnQueue(S,3);
    EnQueue(S,4);
    DeQueue(S,data);
    EnQueue(S,5);
    DeQueue(S,data);
}

