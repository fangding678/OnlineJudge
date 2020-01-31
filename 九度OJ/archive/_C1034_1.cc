#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100001];

int main()
{
    int n,m,i;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        for(i=0; i<n; ++i)
            cin>>a[i];
        sort(a, a+n);
        cout<<a[n-1];
        for(i=n-2; i>=n-m&&i>=0; --i)
            cout<<" "<<a[i];
        cout<<endl;
    }
    return 0;
}
