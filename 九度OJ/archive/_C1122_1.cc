#include <iostream>

using namespace std;

int main()
{
    int n,i;
    int F[20];
    F[1] = 1;
    F[2] = 2;
    for(i=3; i<20; ++i)
    {
        F[i] = F[i-1] + F[i-2];
    }
    while(cin>>n)
    {
        cout<<F[n]<<endl;
    }
    return 0;
}
