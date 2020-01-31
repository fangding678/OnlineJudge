#include <iostream>
#include <algorithm>

using namespace std;

int Tree[101];
struct Edge
{
    int a,b;
    int cost;
    bool operator < (const Edge &A) const
    {
        return cost < A.cost;
    }
}edge[5001];
int findRoot(int x)
{
    if(Tree[x] == -1)
        return x;
    int ret,tmp;
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
    int flag;
    int i,t;
    int p1,p2,c;
    int ans;
    while(cin>>n)
    {
        if(n == 0)
            break;
        m = n*(n-1)/2;
        for(i=0; i<=n; ++i)
        {
            Tree[i] = -1;
        }
        ans = 0;
        t = 0;
        for(i=0; i<m; ++i)
        {
            cin>>p1>>p2>>c>>flag;
            if(flag == 0)
            {
                edge[t].a = p1;
                edge[t].b = p2;
                edge[t].cost = c;
                t++;
            }
            else
            {
                p1 = findRoot(p1);
                p2 = findRoot(p2);
                if(p1 != p2) //ifÅÐ¶Ï¾ø¶Ô²»ÄÜÂ©µô¡­¡­
                    Tree[p1] = p2;
            }
        }
        sort(edge, edge+t);
        for(i=0; i<t; ++i)
        {
            p1 = findRoot(edge[i].a);
            p2 = findRoot(edge[i].b);
            if(p1 != p2)
            {
                Tree[p1] = p2;
                ans += edge[i].cost;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
