#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string a[101];
    bool mark[101];
    int n,t,i;
    while(cin>>n)
    {
        memset(mark, 0, 101*sizeof(mark[0]));
        for(i=0; i<n; ++i)
        {
            cin>>t;
            cin>>a[t];
            mark[t] = true;
        }
        for(i=100; i>=0; --i)
        {
            if(mark[i])
                cout<<a[i]<<endl;
        }
    }
    return 0;
}
