#include <stdio.h>
#include <stdlib.h>
#define M 0x7fffffff
int main()
{
    long long L1,L2,L3,C1,C2,C3;
    int a,b,n;
    long long t;
    int i,j,k;
    long long sum,min;
    long long dp[2000];
    long long len[2000],l[2000];
    while(~scanf("%lld%lld%lld%lld%lld%lld%d%d%d",&L1,&L2,&L3,&C1,&C2,&C3,&a,&b,&n))
    {
        l[0] = 0;
        len[0] = 0;
        for(k=1; k<n; ++k)
        {
            scanf("%lld",&l[k]);
        }
        for(k=1; k<n; ++k)
        {

            len[k] = l[k] - l[k-1];
        }
        if(a>b)
        {
            k = a;
            a = b;
            b = k;
        }
        dp[a] = 0;
        for(i=a+1; i<=b; ++i)
        {
            min = dp[i-1] + C3;
            sum = 0;
            for(j=i-1; j>=a; j--)
            {
                sum += len[j];
                if(sum <= L1)
                    t = dp[j] + C1;
                else if(sum <= L2)
                    t = dp[j] + C2;
                else if(sum <= L3)
                    t = dp[j] + C3;
                else
                    break;
                if(t < min)
                    min = t;
            }
            dp[i] = min;
        }
        printf("%lld\n",dp[b]);
    }
    return 0;
}
