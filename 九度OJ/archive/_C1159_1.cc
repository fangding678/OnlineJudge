#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[100];
    int n,p,i,t,s;
    int leftr,rightl;
    int ans;
    while(cin>>n)
    {
        for(i=1;i<100;++i)
            a[i] = -2;
        for(i=0;i<n;++i)
        {
            cin>>t>>s;
            a[t] = s;
            if(s==0)
                p = t;
        }
        leftr=rightl=0;
        for(i=1; i<p; ++i)
        {
            if(a[i]==1)
            {
                ++leftr;
            }
        }
        for(i=p+1; i<100; ++i)
        {
            if(a[i]==-1)
            {
                ++rightl;
            }
        }
        if(leftr > rightl)
        {
            for(i=p-1; rightl>=0; --i)
            {
                if(a[i] == 1)
                {
                    rightl--;
                    if(rightl < 0)
                        break;
                }
            }
            ans = 100-i;
        }
        else if(leftr < rightl)
        {
            for(i=p+1; i<100; ++i)
            {
                if(a[i]==-1)
                {
                    leftr--;
                    if(leftr < 0)
                        break;
                }
            }
            ans = i;
        }
        else
        {
            ans = -1;
        }
        if(ans == -1)
            cout<<"Cannot fall!"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
