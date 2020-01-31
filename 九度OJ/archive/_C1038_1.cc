#include <iostream>

using namespace std;

int main()
{
    int n,t,i;
    int a[15];
    a[0] = 1;
    a[1] = 1;
    t = a[1];
    i = 1;
    do
    {
        a[i+1] = a[i]*(i+1);
        ++i;
    }while(a[i]<=1000000);
    t = i-1;
    while(cin>>n)
    {
        if(n==0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(i=t; i>=0; --i)
        {
            if(n>=a[i])
                n -= a[i];
        }
        if(n == 0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
