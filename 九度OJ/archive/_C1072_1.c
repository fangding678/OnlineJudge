#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[200]={0};
    int i,j,k,count=0;
    for(i=0;i<=5;i++)
        for(j=0;j<=4;j++)
            for(k=0;k<=6;k++)
                a[8*i+j*10+18*k]=1;
    for(i=1;i<200;i++)
        if(a[i]==1)
            count++;
    printf("%d\n",count);
    return 0;
}
