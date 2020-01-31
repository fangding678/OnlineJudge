#include <iostream>

using namespace std;

int main()
{
    int p,n;
    bool tag[301];
    int a[301];
    int i,t;
    while(cin>>p>>n)
    {
        for(i=0; i<301; ++i)
            tag[i] = false;
        for(i=0; i<n; ++i)
            cin>>a[i];
        for(i=0; i<n; ++i)
        {
            t = a[i];
            if(t >= p)
                t = t%p;
            if(tag[t])
                break;
            tag[t] = true;
        }
        if(i==n)
            cout<<-1<<endl;
        else
            cout<<i+1<<endl;
    }
    return 0;
}
