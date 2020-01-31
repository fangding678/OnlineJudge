#include <iostream>

using namespace std;

int F[31];
void init()
{
    F[0] = 0;
    F[1] = 1;
    for(int i=2; i<31; ++i)
        F[i] = F[i-1] + F[i-2];
}

int main()
{
    int n;
    init();
    while(cin>>n)
    {
        cout<<F[n]<<endl;
    }
    return 0;
}
