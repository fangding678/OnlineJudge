#include <stdio.h>
#include <stdlib.h>
typedef struct BiNode
{
    int data;
    struct BiNode *lchild,*rchild;
}BiNode,*Tree;
void PreOrder(Tree T)
{
    if(T)
    {
        printf("%d ",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(Tree T)
{
    if(T)
    {
        InOrder(T->lchild);
        printf("%d ",T->data);
        InOrder(T->rchild);
    }
}
void PostOrder(Tree T)
{
    if(T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%d ",T->data);
    }
}
void FreeTree(Tree T)
{
    if(T)
    {
        FreeTree(T->lchild);
        FreeTree(T->rchild);
        free(T);
    }
}

int main()
{
    int n,i,*a;
    Tree T,s,r;
    while(~scanf("%d",&n))
    {
        T=(Tree)malloc(sizeof(BiNode));
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        T->data=a[0];
        T->lchild=T->rchild=NULL;
        for(i=1;i<n;i++)
        {
            r=T;
            while(r)
            {
                if(r->data>a[i])
                {
                    if(r->lchild==NULL)
                    {
                        s=(Tree)malloc(sizeof(BiNode));
                        s->data=a[i];
                        s->lchild=s->rchild=NULL;
                        r->lchild=s;
                    }
                    r=r->lchild;
                }
                else if(r->data<a[i])
                {
                    if(r->rchild==NULL)
                    {
                        s=(Tree)malloc(sizeof(BiNode));
                        s->data=a[i];
                        s->lchild=s->rchild=NULL;
                        r->rchild=s;
                    }
                    r=r->rchild;
                }
                else
                    r=NULL;
            }
        }
        free(a);
        PreOrder(T);
        printf("\n");
        InOrder(T);
        printf("\n");
        PostOrder(T);
        printf("\n");
        FreeTree(T);
    }
    return 0;
}
