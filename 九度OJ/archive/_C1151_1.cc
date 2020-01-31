#include <iostream>

using namespace std;

int main()
{
    int n,p,q,t;
    bool flag;
    while(cin>>n)
    {
        while(n--)
        {
            flag = false;
            cin>>p>>q;
            for(int i=0; i<16; ++i)
            {
                t = ((p<<i) | (p>>(16-i))) & 65535;
                if(t==q)
                {
                    flag = true;
                    break;
                }
            }
            cout<<(flag ? "YES" : "NO")<<endl;
        }
    }
    return 0;
}
