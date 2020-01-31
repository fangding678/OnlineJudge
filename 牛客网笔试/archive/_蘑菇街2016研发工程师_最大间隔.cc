#include <iostream>

using namespace std;

int main()
{
    int a[101];
    int i,tmax,tmin,n;
    while(cin>>n)
    {
        cin>>a[0];
        if(n==1 || n==2)
            cout<<0<<endl;
        tmax = 0;
        tmin = 0x07ffffff;
        for(i=1; i<n; ++i)
        {
            cin>>a[i];
            if(a[i] - a[i-1] > tmax)
                tmax = a[i] - a[i-1];
            if(i > 1 && tmin > a[i]-a[i-2])
            {
                tmin = a[i] - a[i-2];
            }
        }
        cout<<(tmax>tmin ? tmax : tmin)<<endl;
    }
    return 0;
}
