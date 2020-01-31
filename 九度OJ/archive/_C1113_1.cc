#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int m,n;
    int ans,t,i,r;
    while(cin>>m>>n)
    {
        if(n==0 && m==0)
            break;
        ans = 0;
        t = m;
        r = m;
        i=0;
        while(t <= n)
        {
            i++;
            t *= 2;
            r = 2*r + 1;
        }
        t /= 2;
        r /= 2;
        ans = pow(2, i-1) - 1;
        if(r < n)
            n = r;
        for(i=t; i<=n; ++i)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}



/*此法方便，但是超时……
#include <iostream>

using namespace std;

void countTree(int m, int n,int &ans)
{
    if(m<=n)
    {
        ans++;
        countTree(2*m, n, ans);
        countTree(2*m+1, n, ans);
    }
}

int main()
{
    int m,n;
    int ans;
    while(cin>>m>>n)
    {
        if(n==0 && m==0)
            break;
        ans = 0;
        countTree(m, n, ans);
        cout<<ans<<endl;
    }
    return 0;
}
*/
