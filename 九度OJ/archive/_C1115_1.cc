#include <iostream>

using namespace std;

int main()
{
    int a;
    int t;
    int ans;
    while(cin>>a)
    {
        ans = 0;
        for(int i=0; i<5; ++i)
        {
            cin>>t;
            if(t>=a)
                continue;
            ans += t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
