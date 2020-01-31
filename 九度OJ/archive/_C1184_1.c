#include <stdio.h>
#include <stdlib.h>
char str[110];
char c;
int n;
typedef struct Node
{
    char e;
    struct Node *lchild;
    struct Node *rchild;
}Tree;
void gouzhao(Tree **T)
{
    c=str[n++];
    if(c=='#')
        *T=NULL;
    else if(c!='#')
    {
        *T=(Tree *)malloc(sizeof(Tree));
        (*T)->e=c;
        gouzhao(&(*T)->lchild);
        gouzhao(&(*T)->rchild);
    }
}
void inOrder(Tree *T)
{
    if(T!=NULL)
    {
        inOrder(T->lchild);
        printf("%c ",T->e);
        inOrder(T->rchild);
    }
}
int main()
{
    Tree *T;
    while(gets(str)!=NULL)
    {
        n=0;
        gouzhao(&T);
        inOrder(T);
        printf("\n");
    }
    return 0;
}
