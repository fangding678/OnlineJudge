#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int Tree[101];
struct Point
{
    double x,y;
    double Dis(Point &a)
    {
        double tmp;
        tmp = sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
        return tmp;
    }
}P[101];
struct E
{
    int a,b;
    double dis;
    bool operator < (const E & A) const
    {
        return dis < A.dis;
    }
}edge[5050];
int findRoot(int x)
{
    if(Tree[x] == -1)
        return x;
    else
    {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main()
{
    int n,i,j,cnt,a,b;
    double ans;
    while(cin>>n)
    {
        for(i=1; i<=n; ++i)
        {
            cin>>P[i].x>>P[i].y;
            Tree[i] = -1;
        }
        cnt = 0;
        for(i=1; i<=n; ++i)
        {
            for(j=i+1; j<=n; ++j)
            {
                edge[cnt].a = i;
                edge[cnt].b = j;
                edge[cnt].dis = P[i].Dis(P[j]);
                cnt++;
            }
        }
        sort(edge, edge+cnt);
        ans = 0;
        for(i=0; i<cnt; ++i)
        {
            a = findRoot(edge[i].a);
            b = findRoot(edge[i].b);
            if(a!=b)
            {
                Tree[b] = a;
                ans += edge[i].dis;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
