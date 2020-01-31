#include <iostream>
#include <cstdio>

using namespace std;

struct BiTNode
{
    int data;
    int left;
    int right;
    bool isRoot;
};

int createTree(BiTNode a[], int n)
{
    int i;
    char c;
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&(a[i].data));
        a[i].left = a[i].right = -1;
        a[i].isRoot = true;
    }
    for(i=1; i<=n; ++i)
    {
        while((getchar()) != '\n');
        scanf("%c",&c);
        if(c == 'd')
        {
            scanf("%d%d",&(a[i].left),&(a[i].right));
            a[a[i].left].isRoot = false;
            a[a[i].right].isRoot = false;
        }
        else if(c == 'l')
        {
            scanf("%d",&(a[i].left));
            a[a[i].left].isRoot = false;
        }
        else if(c == 'r')
        {
            scanf("%d",&(a[i].right));
            a[a[i].right].isRoot = false;
        }
    }
    for(i=1; i<=n; ++i)
    {
        if(a[i].isRoot)
            break;
    }
    return i;
}

void mirrorTree(BiTNode a[], int i, int n)
{
    if(i<=0 || i>n)
        return ;
    if(a[i].left == -1 && a[i].right == -1)
        return ;
    int t;
    t = a[i].right;
    a[i].right = a[i].left;
    a[i].left = t;
    if(a[i].left != -1)
        mirrorTree(a, a[i].left, n);
    if(a[i].right != -1)
        mirrorTree(a, a[i].right, n);
}

void printTree(BiTNode a[], int i)
{
    if(i==1)
        printf("%d",a[i].data);
    else if(i>1)
        printf(" %d",a[i].data);
    if(a[i].left != -1)
        printTree(a, a[i].left);
    if(a[i].right != -1)
        printTree(a, a[i].right);
}

int main()
{
    BiTNode a[1010];
    int n,root;
    while(EOF != scanf("%d", &n))
    {
        if(n == 0)
        {
            printf("NULL\n");
            continue;
        }
        root = createTree(a, n);
        mirrorTree(a, root, n);
        printTree(a, root);
        printf("\n");
    }
    return 0;
}
