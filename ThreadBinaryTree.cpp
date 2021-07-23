//带头节点的二叉树的前序线索化
#include <iostream>

using namespace std;

//二叉树的结构体
typedef struct Node
{
    char data;
    int ltag;
    int rtag;
    struct Node *lchild;
    struct Node *rchild;
}*BiTree;
BiTree pre;
//前序创建二叉树
void createBiTree(BiTree &Tree)
{
    char data;
    cin>>data;
    if(data=='#')
    {
        Tree = NULL;
    }
    else
    {
        Tree = new Node();
        Tree->data = data;
        Tree->ltag=0;
        Tree->rtag=0;
        createBiTree(Tree->lchild);
        createBiTree(Tree->rchild);
    }
}
//前序加线索化的函数
void preThreading(BiTree &Tree)
{
    if(Tree)
    {
        if(Tree->lchild==NULL)
        {
            Tree->ltag=1;
            Tree->lchild=pre;
        }
        if(pre->rchild==NULL)
        {
            pre->rtag=1;
            pre->rchild=Tree;
        }
        pre = Tree;
        if(Tree->ltag==0)
        {
            preThreading(Tree->lchild);
        }
        if(Tree->rtag==0)
        {
            preThreading(Tree->rchild);
        }
    }
}
//前序线索化，加上头节点
void preXianBiTree(BiTree Tree,BiTree &Thrt)
{
    Thrt = new Node();
    Thrt->ltag = 0;
    Thrt->rtag = 1;
    Thrt->rchild=Thrt;
    if(Tree==NULL)
    {
        Thrt->lchild=Thrt;
    }
    else
    {
        Thrt->lchild=Tree;
        pre = Thrt;
        preThreading(Tree);
        pre->rchild=Thrt;
        pre->rtag=1;
        Thrt->rchild=pre;
    }
}
//遍历前序加线索化的函数
void preBiTree(BiTree Tree)
{
    BiTree p;
    p = Tree->lchild;
    while(p!=Tree)
    {
        while(p->lchild!=NULL&&p->ltag==0)
        {
            cout<<p->data<<" ";
            p = p->lchild;
        }
        cout<<p->data<<" ";

        if(p->ltag==1)
        {
            p = p->rchild;
        }
        while(p!=Tree)
        {
            if(p->lchild!=NULL&&p->ltag==0)
            {
                break;
            }

            cout<<p->data<<" ";
            p = p->rchild;
        }
    }
}
int main()
{
    BiTree Tree,Thrt;
    cout<<"请输入你要创建的二叉树的数据(按先序遍历创建的二叉树#为空节点的表示)\n";
    createBiTree(Tree);
    pre = new Node();
    pre->rchild=NULL;
    preXianBiTree(Tree,Thrt);
    preBiTree(Thrt);
    return 0;
}
//AB#D##CE###