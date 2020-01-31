#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n,t;
    double ans;
    while(cin>>n)
    {
        ans = 0.0;
        for(int i=0;i<n;++i)
        {
            cin>>t;
            ans += t;
        }
        ans /= n;
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
