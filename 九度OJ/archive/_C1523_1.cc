#include <iostream>
#include <cstdio>
#include <queue>

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

void printTree(BiTNode a[], int i)
{
    queue<BiTNode> sq;
    BiTNode bt;
    printf("%d", a[i].data);
    if(a[i].left != -1)
        sq.push(a[a[i].left]);
    if(a[i].right != -1)
        sq.push(a[a[i].right]);
    while(!sq.empty())
    {
        bt = sq.front();
        sq.pop();
        printf(" %d", bt.data);
        if(bt.left != -1)
            sq.push(a[bt.left]);
        if(bt.right != -1)
            sq.push(a[bt.right]);
    }
}

int main()
{
    BiTNode a[1010];
    int n,root;
    while(EOF != scanf("%d", &n))
    {
        root = createTree(a, n);
        printTree(a, root);
        printf("\n");
    }
    return 0;
}
