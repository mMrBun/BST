//
// Created by MrBun on 2021/7/7.
//
#include <iostream>
using namespace std;
#define MaxSize 50
#define ElemType int
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L){
    for(int & i : L.data)
        i=0;
    L.length=0;
}

bool ListInsert(SqList &L,int i,ElemType e)
{
    if(i<1||i>L.length+1)
        return false;
    if(L.length>MaxSize)
        return false;
    for (int j = L.length; j >=i ; j--) {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L,int i,ElemType &e)
{
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

int LocateElem(SqList &L,ElemType e)
{
    for(int j=0;j<L.length;j++)
        if(L.data[j]==e)
            return j;
    cout<<"The locate element you searched is not exists"<<endl;
    return -1;
}

int main()
{
    SqList L;
    int del_val=0;
    InitList(L);
    for(int i=0;i<MaxSize;i++)
        ListInsert(L,i,i);
    ListDelete(L,2,del_val);
    del_val=LocateElem(L,24);
    if(del_val>=0)
        cout<<del_val<<"\t"<<"del success"<<endl;

}
