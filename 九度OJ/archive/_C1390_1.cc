#include <iostream>

using namespace std;

int main()
{
    long long F[71];
    F[0] = 1;
    F[1] = 1;
    int i;
    for(i=2; i<71; ++i)
    {
        F[i] = F[i-2] + F[i-1];
    }
    while(cin>>i)
        cout<<F[i]<<endl;
    return 0;
}
