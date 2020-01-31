#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,ans;
    int i,a[10001];
    while(cin>>n && n!=0)
    {
        for(i=0;i<n;++i)
            cin>>a[i];
        sort(a,a+n);
        if((n&1)==1)
            ans = a[n/2];
        else
            ans = (a[n/2] + a[n/2-1])/2;
        cout<<ans<<endl;
    }
    return 0;
}
