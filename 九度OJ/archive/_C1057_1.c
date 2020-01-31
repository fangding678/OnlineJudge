#include <stdio.h>
int main()
{
    int a[20];
    int i;
    while(scanf("%d",&a[0])!=EOF)
    {
        int b[10]={0},flag=0;
        int z,result;
        for(i=1;i<20;i++)
            scanf("%d",&a[i]);
        for(i=0;i<20;i++)
            if(a[i]<1||a[i]>10)
                flag=1;
        if(flag)
            continue;
        for(i=0;i<20;i++)
            b[a[i]-1]++;
        z=b[0],result=1;
        for(i=1;i<10;i++)
            if(b[i]>z)
            {
                z=b[i];
                result=i+1;
            }
        printf("%d\n",result);
    }
    return 0;
}
