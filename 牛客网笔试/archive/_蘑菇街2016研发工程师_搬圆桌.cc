#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double d;
    long long x1,x2,y1,y2;
    long long dis,dd;
    int r, ans;
    while(cin>>r>>x1>>y1>>x2>>y2)
    {
        dis = ((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
        d = sqrt(dis);
        dd = (long long)d;
        r *= 2;
        ans = dd/r;
        if(dd%r==0 && dd*dd == dis)
            ans--;
        ans++;
        cout<<ans<<endl;
    }
    return 0;
}
