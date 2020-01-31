#include <iostream>

using namespace std;

int main()
{
    long long F[72];
    F[0] = 0;
    F[1] = 1;
    int i;
    for(i=2; i<72; ++i)
    {
        F[i] = F[i-2] + F[i-1];
    }
    while(cin>>i)
        cout<<F[i+1]<<endl;
    return 0;
}
