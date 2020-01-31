#include <stdio.h>
#include <stdlib.h>

typedef struct Date
{
    int year;
    int month;
    int day;
}Date;
int isRun(int n)
{
    return ((n%4==0&&n%100!=0)||n%400==0);
}
int main()
{
    int y,n,i;
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    Date d;
    int b[12];
    b[0]=a[0];
    while(~scanf("%d%d",&y,&n))
    {
        if(y<1||y>3000||n<1||n>366) continue;
        if(isRun(y)) a[1]=29;
        else a[1]=28;
        for(i=1;i<12;i++)
            b[i]=b[i-1]+a[i];
        d.year=y;
        for(i=0;i<12;i++)
            if(b[i]>=n) break;
        d.month=i+1;
        d.day=n-b[i-1];
        printf("%04d-%02d-%02d\n",d.year,d.month,d.day);
    }
    return 0;
}
