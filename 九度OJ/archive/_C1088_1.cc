#include <iostream>
#include <algorithm>

using namespace std;

struct L
{
    int a;
    int b;
    bool operator < (const L &ll) const
    {
        return (a<ll.a || (a==ll.a && b<ll.b));
    }
}lq[101],llq[101];

int main()
{
    int n,m;
    int i,j,t;
    int cnt;
    while(cin>>n>>m)
    {
        for(i=0; i<m; ++i)
        {
            cin>>lq[i].a>>lq[i].b;
            if(lq[i].a>lq[i].b)
            {
                swap(lq[i].a, lq[i].b);
            }
            if(lq[i].a<0)
                lq[i].a = 0;
            if(lq[i].b > n)
                lq[i].b = n;
        }
        sort(lq,lq+m);
        cnt = 0;
        for(i=0;i<m;)
        {
            t = lq[i].b;
            for(j=i+1; j<m && t >= lq[j].a; ++j)
            {
                t = max(t, lq[j].b);
            }
            llq[cnt].a = lq[i].a;
            llq[cnt].b = t;
            i = j;
            cnt++;
        }
        for(i=0; i<cnt; ++i)
        {
            n -= llq[i].b - llq[i].a + 1;
        }
        cout<<n+1<<endl;
    }
    return 0;
}
