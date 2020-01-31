#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
int main()
{
    int n,t,i;
    int a[100]={0};
    BiTree T=(BiTree)malloc(sizeof(BiTNode));
    BiTree s,p;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<1||n>100)
            continue;
        scanf("%d",&t);
        T->data=t;
        T->lchild=NULL;
        T->rchild=NULL;
        a[0]=-1;
        for(i=1;i<n;i++)
        {
            scanf("%d",&t);
            p=(BiTNode *)malloc(sizeof(BiTNode));
            p->data=t;
            p->lchild=NULL;
            p->rchild=NULL;
            s=T;
            while(1)
            {
                if(s->data>t&&s->lchild!=NULL)
                    s=s->lchild;
                if(s->data>t&&s->lchild==NULL)
                    break;
                if(s->data<t&&s->rchild!=NULL)
                    s=s->rchild;
                if(s->data<t&&s->rchild==NULL)
                    break;
            }
            a[i]=s->data;
            if(s->data>t)
                s->lchild=p;
            else
                s->rchild=p;
        }
        for(i=0;i<n;i++)
            printf("%d\n",a[i]);
    }
    return 0;
}
