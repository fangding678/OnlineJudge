#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n,m;
    int a[201],b[201];
    int i,t;
    while(cin>>n>>m)
    {
        memset(a, 0, 201*sizeof(int));
        memset(b, 0, 201*sizeof(int));
        for(i=1; i<=n; ++i)
        {
            cin>>t;
            a[i] = t;
            b[t]++;
        }
        for(i=1; i<=n; ++i)
        {
            if(b[a[i]] == 1)
                cout<<"BeiJu"<<endl;
            else
                cout<<b[a[i]]-1<<endl;
        }
    }
    return 0;
}
