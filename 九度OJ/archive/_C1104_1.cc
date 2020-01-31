#include <iostream>
#include <cstring>

using namespace std;

int prime[1001];
bool mark[1001];
int re[1001];
int cnt;
void init()
{
    memset(mark, 0, 1001*sizeof(mark[0]));
    int i,j;
    cnt = 0;
    for(i=2; i<1001; ++i)
    {
        if(mark[i])
            continue;
        prime[cnt++] = i;
        for(j=i*i; j<1001; j+=i)
        {
            mark[j] = true;
        }
    }
}

int main()
{
    int n,a,k,t;
    int i;
    int c1[1001];
    int c2[1001];
    init();
    while(cin>>n>>a)
    {
        for(i=0; i<1001; ++i)
            c1[i] = c2[i] = 0;
        k = 0x7fffffff;
        for(i=0; i<cnt; ++i)
        {
            t = n;
            while(t)
            {
                t /= prime[i];
                c1[i] += t;
            }
            while(a!=0 && a%prime[i] == 0)
            {
                c2[i]++;
                a /= prime[i];
            }
            if(c2[i] != 0 && k > c1[i]/c2[i])
            {
                k = c1[i]/c2[i];
            }
        }
        cout<<k<<endl;
    }
    return 0;
}
