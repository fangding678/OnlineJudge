#include <stdio.h>
int main()
{
    int a,n;
    while(scanf("%d%d",&a,&n)!=EOF)
    {
        if(a<1||a>9||n>100||n<1)
            continue;
        char sum[101]={0};
        int j,x,y=0;
        for(j=100;j>99-n;j--)
        {
            x=(a*(n-100+j))%10;
            sum[j]=(x+y)%10;
            y=(x+y)/10+(a*(n-100+j))/10;
        }
        for(j=0;j<101;j++)
        {
            if(sum[j]==0&&j<=101-n)
            continue;
            printf("%d",sum[j]);
        }
        printf("\n");
    }
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int pow_1(int ,int);
int main()
{
    int n,a,i;
    int sum,t;
    while(scanf("%d%d",&a,&n)!=EOF)
    {
        if(a<1||a>9||n>100||n<1)
            continue;
        sum=0;
        for(i=0;i<n;i++)
        {
            t=a*pow_1(10,i);
            sum+=t*(n-i);
        }
        printf("%d\n",sum);
    }
    return 0;
}
int pow_1(int m,int k)
{
    if(k==0)
        return 1;
    return m*pow_1(m,k-1);
}
*/

