//
// Created by MrBun on 2021/7/8.
//

#include <iostream>
using namespace std;
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode , *LinkList ;

struct Node{
    int data;
    struct Node *next;
};
//头插
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=nullptr;
    cin>>x;
    while(x!=9999){
        s=(LNode*)malloc(sizeof (LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        cin>>x;
    }
    return L;
}
//尾插
LinkList List_TailInsert(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s,*r=L;
    int x;
    cin>>x;
    while(x!=9999){
        s=(LNode*)malloc(sizeof (LNode));
        s->data=x;
        r->next=s;
        r=s;
        cin>>x;
    }
    r->next=nullptr;
    return L;
}
//按位查询
LinkList GetElem(LinkList &L,int i)
{
    int j=1;
    LinkList p=L->next;
    if(i<0)
        return L;
    if(i<1)
        return nullptr;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}
//按值查询
LinkList LocateElem(LinkList &L,ElemType x)
{
    LinkList p=L->next;
    while(p)
    {
        if(p->data==x)
        {
            return p;
        }
        else
        {
            p=p->next;
        }
    }
    return nullptr;
}
//按位插入
LinkList InsertToLocate(LinkList &L,int i)
{
    LinkList p= GetElem(L,i-1),s, result;
    if(p== nullptr)
        return nullptr;
    s=(LinkList) malloc(sizeof(LinkList));
    cin>>s->data;
    s->next=p->next;
    p->next=s;
    result->next=p;
    return result;
}
//按位删除
LinkList LinkDelete(LinkList &L,int i)
{
    if(i<1)
        return nullptr;
    int j=1;
    LinkList p= GetElem(L,i-1),s= GetElem(L,i);
    p->next=s->next;
    s= nullptr;
    free(s);
    return L;
}
//获取表长
int GetLength(LinkList &L)
{
    LinkList p=L->next;
    int k=0;
    while(p)
    {
        p=p->next;
        k++;
    }
    return k;
}

int main()
{
    LinkList node;
    List_TailInsert(node);
    LinkList result=GetElem(node,2);
    cout<<result->data<<endl;
    result= LocateElem(node,5);
    if(result)
        cout<<result->data<<endl;
    else
        cout<<"The value you found was not exists"<<endl;
    result=InsertToLocate(node,2);
    result= LinkDelete(node,2);
    cout<<GetLength(node)<<endl;
}