//
// Created by MrBun on 2021/7/14.
//
#include <iostream>
#define MaxSize 50
#define ElemType int
typedef struct{
    ElemType data[MaxSize];
    int top;
} SqStack;
//初始化栈
void initStack(SqStack &S)
{
    S.top=-1;
}
//判断栈空
bool stackEmpty(SqStack S)
{
    if(S.top==-1)
        return true;
    else
        return false;
}
//入栈
bool Push(SqStack &S,ElemType x)
{
    if(S.top==MaxSize-1)
        return false;
    S.data[++S.top]=x;
    return true;
}
//出栈
bool Pop(SqStack &S,ElemType &x)
{
    if(S.top==-1)
        return false;
    x=S.data[S.top--];
    return true;
}
//获取栈顶元素
bool GetTop(SqStack &S,ElemType &x)
{
    if(S.top==-1)
        return false;
    x=S.data[S.top];
    return true;
}
int main()
{
    int data;
    SqStack S;
    initStack(S);
    Push(S,4);
    Push(S,5);
    Push(S,6);
    Push(S,7);
    Push(S,8);
    Push(S,9);
    Push(S,1);
    Pop(S,data);
    printf("%d\n",data);
    GetTop(S,data);
    printf("%d\n",data);
}