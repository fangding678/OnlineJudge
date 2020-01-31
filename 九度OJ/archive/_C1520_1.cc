#include <iostream>
#include <cstdio>

using namespace std;

struct BiTNode
{
    int data;
    struct BiTNode *left,*right;
};

void createTree(BiTNode a[], int n)
{
    int i;
    int l,r,t;
    BiTNode *pt1 = NULL;
    for(i=1; i<=n; ++i)
    {
        pt1 = &(a[i]);
        cin>>t;
        if(t == 0)
        {
            pt1->left = NULL;
            pt1->right = NULL;
        }
        else if(t == 1)
        {
            cin>>l;
            pt1->right = NULL;
            pt1->left = &(a[l]);
        }
        else if(t == 2)
        {
            cin>>l>>r;
            pt1->left = &(a[l]);
            pt1->right = &(a[r]);
        }
    }
}

bool DoesT1HaveT2(BiTNode *T1, BiTNode *T2)
{
    if(T2 == NULL)
        return true;
    if(T1 == NULL)
        return false;
    if(T1->data != T2->data)
        return false;
    return DoesT1HaveT2(T1->left, T2->left) && DoesT1HaveT2(T1->right, T2->right);

}

bool hasSubTree(BiTNode *T1, BiTNode *T2)
{
    bool result = false;
    if(T1 && T2)
    {
        if(T1->data == T2->data)
            result = DoesT1HaveT2(T1, T2);
        if(!result)
            result = hasSubTree(T1->left, T2);
        if(!result)
            result = hasSubTree(T1->right, T2);
    }
    return result;
}

int main()
{
    int n,m,i;
    BiTNode a[1010],b[1010],*T1, *T2;
    while(EOF != scanf("%d%d",&n,&m))
    {
        T1 = &(a[1]);
        T2 = &(b[1]);
        for(i=1; i<=n; ++i)
        {
            cin>>a[i].data;
            a[i].left = a[i].right = NULL;
        }
        createTree(a, n);
        for(i=1; i<=m; ++i)
        {
            cin>>b[i].data;
            b[i].left = b[i].right = NULL;
        }
        createTree(b, m);
        if(n==0 || m==0)
        {
            cout<<"NO\n";
            continue;
        }
        if(hasSubTree(T1, T2))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
