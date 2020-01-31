#include <iostream>

using namespace std;

int main()
{
    long long F[51];
    int i;
    F[1] = 1;
    for(i=2; i<51; ++i)
    {
        F[i] = F[i-1]*2;
    }
    while(cin>>i)
        cout<<F[i]<<endl;
    return 0;
}
