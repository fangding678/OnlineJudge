#include <stdio.h>
#include <stdlib.h>

int isRun(int year)
{
    return ((year%400==0||(year%4==0&&year%100!=0)));
}
int main()
{
    int year,month,day;
    int i,result;
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    while(~scanf("%d%d%d",&year,&month,&day))
    {
        if(isRun(year)) a[1]=29;
        else a[1]=28;
        result=day;
        for(i=0;i<month-1;i++)
            result+=a[i];
        printf("%d\n",result);
    }
    return 0;
}
