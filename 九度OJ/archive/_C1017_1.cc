#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
    int a;
    int next;
    int dist;
    bool operator < (const Point &A) const
    {
        return dist<A.dist;
    }
}p[5000];

int Tree[101];
int findRoot(int x)
{
    int t,ret;
    if(Tree[x] == -1)
        return x;
    t = x;
    while(Tree[x] != -1)
    {
        x = Tree[x];
    }
    ret = x;
    Tree[t] = ret;
    return ret;
}

int main()
{
    int n,m;
    int i;
    int cost;
    int pstart,pend;
    while(cin>>n)
    {
        if(n == 0)
            break;
        m = n*(n-1)/2;
        cost = 0;
        for(i=1; i<=n; ++i)
            Tree[i] = -1;
        for(i=0; i<m; ++i)
            cin>>p[i].a>>p[i].next>>p[i].dist;
        sort(p,p+m);
        for(i=0; i<m; ++i)
        {
            pstart = findRoot(p[i].a);
            pend = findRoot(p[i].next);
            if(pstart!=pend)
            {
                Tree[pend] = pstart;
                cost += p[i].dist;
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
