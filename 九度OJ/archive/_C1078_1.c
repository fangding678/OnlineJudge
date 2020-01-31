#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tnode
{
    struct Tnode *lchild,*rchild;
    char e;
}Tnode;
Tnode Tree[50];
int loc;
char str1[30],str2[30];
Tnode *Create()
{
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
Tnode *Build(int low1,int high1,int low2,int high2)
{
    int i=low2;
    Tnode *ret=Create();
    ret->e=str1[low1];
    while(str1[low1]!=str2[i])
        i++;
    if(i!=low2)
        ret->lchild=Build(low1+1,low1+i-low2,low2,i-1);
    if(i!=high2)
        ret->rchild=Build(low1+i-low2+1,high1,i+1,high2);
    return ret;
}
void PostOrder(Tnode *t)
{
    if(t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        printf("%c",t->e);
    }
}
int main()
{
    int len1,len2;
    Tnode *Tr;
    while((gets(str1)!=NULL)&&(gets(str2)!=NULL))
    {
        loc=0;
        len1=strlen(str1);
        len2=strlen(str2);
        Tr=Build(0,len1-1,0,len2-1);
        PostOrder(Tr);
        printf("\n");
    }
    return 1;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tnode
{
    char e;
    struct Tnode *lchild,*rchild;
}Tnode;
int loc;
Tnode T[50];
char str1[30],str2[30];

Tnode *Create()
{
    T[loc].lchild=T[loc].rchild=NULL;
    return &T[loc++];
}
void PostOrder(Tnode *t)
{
    if(t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        printf("%c",t->e);
    }
}
Tnode *build(int low1,int high1,int low2,int high2)
{
    int index,i;
    Tnode *ret=Create();
    ret->e=str1[low1];
    for(i=low2;i<=high2;i++)
        if(str2[i]==str1[low1])
        {
            index=i;
            break;
        }
    if(index!=low2)
        ret->lchild=build(low1+1,low1+index-low2,low2,index-1);
    if(index!=high2)
        ret->rchild=build(low1+index-low2+1,high1,index+1,high2);
    return ret;
}

int main()
{
    int len1,len2;
    while(~scanf("%s",str1))
    {
        scanf("%s",str2);
        len1=strlen(str1);
        len2=strlen(str2);
        loc=0;
        Tnode *Tree=build(0,len1-1,0,len2-1);
        PostOrder(Tree);
        printf("\n");
    }
    return 0;
}
*/
