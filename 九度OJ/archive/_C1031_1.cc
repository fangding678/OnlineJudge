#include <iostream>

using namespace std;

int main()
{
    int ans;
    int n;
    while(cin>>n)
    {
        if(n == 0)
            break;
        ans = 0;
        while(n != 1)
        {
            if(n & 1)
                n += (n+1)/2;
            else
                n >>= 1;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
