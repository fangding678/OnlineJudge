#include <iostream>

using namespace std;

void Result(long long a, int m)
{
    if(a/m)
    {
        Result(a/m, m);
    }
    cout<<a%m;
}
int main()
{
    int m;
    long long a,b;
    while(cin>>m)
    {
        if(m<=1 || m>=10)
            break;
        cin>>a>>b;
        a += b;
        Result(a, m);
        cout<<endl;
    }
    return 0;
}
