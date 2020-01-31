#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
    int n,i;
    int score;
    int s[10];
    double sums,sum;
    double avg;
    while(scanf("%d",&n) != EOF)
    {
        sums = 0;
        sum = 0;
        for(i=0; i<n; ++i)
        {
            scanf("%d",&s[i]);
            sums += s[i];
        }
        for(i=0; i<n; ++i)
        {
            scanf("%d",&score);
            if(score >= 90)
                sum += s[i]*4;
            else if(score >= 85)
                sum += s[i]*3.7;
            else if(score >= 82)
                sum += s[i]*3.3;
            else if(score >= 78)
                sum += s[i]*3;
            else if(score >= 75)
                sum += s[i]*2.7;
            else if(score >= 72)
                sum += s[i]*2.3;
            else if(score >= 68)
                sum += s[i]*2;
            else if(score >= 64)
                sum += s[i]*1.5;
            else if(score >= 60)
                sum += s[i];
        }
        avg = sum / sums;
        printf("%.2lf\n",avg);
        //cout<<fixed<<setprecision(2)<<avg<<endl;
    }
    return 0;
}
