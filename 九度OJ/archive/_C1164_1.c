#include <stdio.h>
#include <stdlib.h>
int xuanzhuan(int a[][10],int b[][10],int n)
{
    int i,j;
    int flag1=1,flag2=1,flag3=1,flag0=1;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j])
                flag0=0;
            if(a[i][j]!=b[j][n-1-i])
                flag1=0;
            if(a[i][j]!=b[n-1-i][n-1-j])
                flag2=0;
            if(a[i][j]!=b[n-1-j][i])
                flag3=0;
        }
    if(flag0==1)
        return 0;
    else if(flag1==1)
        return 90;
    else if(flag2==1)
        return 180;
    else if(flag3==1)
        return 270;
    else
        return -1;
}
int main()
{
    int a[10][10],b[10][10];
    int n,i,j;
    while(~scanf("%d",&n))
    {
        if(n<1||n>9)
            continue;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&b[i][j]);
        printf("%d\n",xuanzhuan(a,b,n));
    }
    return 0;
}
