#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdio>

using namespace std;

double c[31];
int ci[31];
int dp[3000001];
char ch;
bool flag;
double price;
int sum;


void Pro(int t, int i)
{
    flag = false;
    while(t--)
    {
        scanf(" %c:%lf",&ch,&price);
        if(!(ch=='A' || ch=='B' || ch=='C'))
        {
            c[i] = -1;
            flag = 1;
        }
        if((ch=='A' || ch=='B' || ch=='C') && (!flag))
        {
            if(price <= 600)
                c[i] += price;
            else
            {
                flag = 1;
                c[i] = -1;
                flag = true;
            }
        }
    }
    if(c[i] > 1000 || flag)
        c[i] = -1;
}
int main()
{
    double Q;
    int N;
    int i,j,t;
    double result;
    while(cin>>Q>>N)
    {
        if(N == 0)
            break;
        if(Q>30000)
            Q = 30000;
        sum = Q*100;
        for(i=0; i<N; ++i)
        {
            cin>>t;
            c[i] = 0;
            Pro(t, i);
        }
        for(i=0; i<=sum; ++i)
        {
            dp[i] = 0;
        }
        j = 0;
        for(i=0; i<N; ++i)
        {
            if(c[i] != -1)
                ci[j++] = 100*c[i];
        }
        N = j;
        for(i=0; i<N; ++i)
        {
            for(j=sum; j>= ci[i]; --j)
            {
                if(dp[j] < dp[j-ci[i]] + ci[i])
                {
                    dp[j] = dp[j-ci[i]] + ci[i];
                }
            }
        }
        result = ((double)dp[sum])/100.0;
        cout<<fixed<<setprecision(2)<<result<<endl;
    }
    return 0;
}
