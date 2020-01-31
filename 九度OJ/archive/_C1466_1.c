#include <stdio.h>
#include <stdlib.h>
int Num(int a)
{
    int sum=0,i=1;
    while(i)
    {
        if((a&1)==0) sum++;
        else i=0;
        a=a>>1;
    }
    return sum;
}
int main()
{
    int n=1,m,i;
    int sum;
    while(n!=0)
    {
        sum=0;
        scanf("%d%d",&n,&m);
        if(n<=0||n>10000||m<0||m>n)
            continue;
        for(i=n;i>n-m;i--)
            sum+=Num(i);
        printf("%d\n",sum);
    }
    return 0;
}
