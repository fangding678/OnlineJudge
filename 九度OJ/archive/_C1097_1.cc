#include <iostream>
#include <algorithm>

using namespace std;

int arr1[1000001],arr2[1000001];
int arr[2000001];

int main()
{
    int T,n,m;
    int i,cnt;
    int a,b,c,d;
    int t1,t2;
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(i=1; i<=n; ++i)
            cin>>arr1[i];
        for(i=1; i<=m; ++i)
            cin>>arr2[i];
        cin>>a>>b>>c>>d;
        t1 = b-a;
        t2 = d-c;
        if(t2==t1)
            cout<<arr1[b]<<endl;
        else if(t2>t1)
        {
            d = c + (t2-t1) -1;
            cnt = (c+d)/2;
            cout<<arr2[cnt]<<endl;
        }
        else
        {
            a = b - (t1-t2) + 1;
            cnt = (a+b)/2;
            cout<<arr1[cnt]<<endl;
        }
    }
    return 0;
}
