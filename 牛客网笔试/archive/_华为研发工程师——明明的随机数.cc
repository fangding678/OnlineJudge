#include <iostream>

using namespace std;

int main()
{
    bool a[1001];
    int n;
    int i,t;
    while(cin>>n)
    {
        for(i=0; i<1001; ++i)
            a[i] = false;
        for(i=0; i<n; ++i)
        {
            cin>>t;
            a[t] = true;
        }
        for(i=0; i<1001; ++i)
        {
            if(a[i])
                cout<<i<<endl;
        }
    }
    return 0;
}
