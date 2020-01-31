#include <iostream>

using namespace std;

int cal(int n)
{
    return n/2;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<cal(n)<<endl;
    }
    return 0;
}
