#include <iostream>
#include <cstring>

using namespace std;

const int N= 1000000;
int prime[10001];
bool mark[N];
void init()
{
    int i,j,t;
    memset(mark, 0, sizeof(mark[0])*N);
    for(i=2; i<1001; ++i)
    {
        for(j=i*i; j<=N; j+=i)
        {
            mark[j] = true;
        }
    }
    t = 1;
    for(i=2; t<10001&&i<N; ++i)
    {
        if(!mark[i])
            prime[t++] = i;
    }
}
int main()
{
    init();
    int k;
    while(cin>>k)
    {
        cout<<prime[k]<<endl;
    }
    return 0;
}
