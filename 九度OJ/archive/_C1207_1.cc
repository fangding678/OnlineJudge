#include <iostream>
#include <cstring>

using namespace std;

int prime[5000];
bool mark[40001];
int cnt;
void init()
{
    int i,j;
    cnt = 0;
    for(i=2; i<40001; i++)
        mark[i] = false;
    for(i=2; i<40001; i++)
    {
        if(mark[i])
            continue;
        prime[cnt++] = i;
        for(j=i*i; j<40001; j+=i)
        {
            mark[j] = true;
        }
    }
}

int main()
{
    int n;
    init();
    int ans,i;
    //cout<<cnt<<endl;
    while(cin>>n)
    {
        ans = 0;
        for(i=0; i<cnt && n>=prime[i]; ++i)
        {
            while(n%prime[i] == 0)
            {
                n /= prime[i];
                ans++;
            }
        }
        if(n>1)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}
