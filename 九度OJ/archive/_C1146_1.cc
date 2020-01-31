#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[31],n;
    int ans[100];
    int i,j;
    int cnt;
    while(cin>>n)
    {
        if(n==0)
            break;
        cnt = 0;
        for(i=1; i<=n; ++i)
        {
            cin>>a[i];
        }
        for(i=n; i>=1; --i)
        {
            if(a[i] == i)
                continue;
            for(j=2; j<i; ++j)
            {
                if(a[j] == i)
                {
                    reverse(a+1, a+j+1);
                    ans[cnt++] = j;
                    break;
                }
            }
            reverse(a+1, a+i+1);
            ans[cnt++] = i;
        }
        cout<<cnt;
        for(i=0; i<cnt; ++i)
            cout<<" "<<ans[i];
        cout<<endl;
    }
    return 0;
}

