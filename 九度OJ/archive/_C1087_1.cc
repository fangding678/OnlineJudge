#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


int yueShu(int x)
{
    int q = sqrt(x);
    int i;
    int re = 0;
    if(x == 1)
        return 1;
    if(x == 2)
        return 2;
    if(x == 3)
        return 2;
    for(i=2; i<=q; ++i)
    {
        if(x%i == 0)
            re += 2;
    }
    re += 2;
    if(q*q == x)
        re--;
    return re;
}
int main()
{
    int a[1001];
    int n;
    int i;
    while(cin>>n)
    {
        if(n == 0)
            break;
        for(i=0; i<n; ++i)
            cin>>a[i];
        for(i=0; i<n; ++i)
            cout<<yueShu(a[i])<<endl;
    }
    return 0;
}
