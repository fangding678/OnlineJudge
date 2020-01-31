#include <iostream>
#include <algorithm>

using namespace std;

const int N = 101;
struct Edge
{
    int a,b;
    int cost;
    bool operator < (const Edge &A) const
    {
        return cost < A.cost;
    }
}edge[N];
int Tree[N];

int findRoot(int x)
{
    if(Tree[x] == -1)
        return x;
    int tmp,ret;
    tmp = x;
    while(Tree[x] != -1)
    {
        x = Tree[x];
    }
    ret = x;
    x = tmp;
    while(Tree[x] != -1)
    {
        tmp = Tree[x];
        Tree[x] = ret;
        x = tmp;

    }
    return ret;
}

int main()
{
    int n,m;
    int i,s,e;
    int result;
    while(cin>>n>>m)
    {
        if(n == 0)
            break;
        for(i=1; i<=n; ++i)
        {
            cin>>edge[i].a>>edge[i].b>>edge[i].cost;
        }
        for(i=1; i<=m; ++i)
        {
            Tree[i] = -1;
        }
        result = 0;
        sort(edge+1, edge+n+1);
        for(i=1; i<=n; ++i)
        {
            s = findRoot(edge[i].a);
            e = findRoot(edge[i].b);
            if(s != e)
            {
                Tree[s] = e;
                result += edge[i].cost;
            }
        }
        s = 0;
        for(i=1; i<=m; ++i)
        {
            if(Tree[i] == -1)
                s++;
        }
        if(s>1)
            cout<<"?"<<endl;
        else
            cout<<result<<endl;
    }
    return 0;
}
