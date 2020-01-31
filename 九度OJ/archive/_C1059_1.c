#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,sum,t;
    for(a=0;a<6;a++)
    {
        sum=a*100;
        for(b=0;b<6;b++)
        {
            t=sum;
            t=sum+b*110;
            for(c=0;c<10;c++)
            {
                if((t+12*c)==532)
                    printf("%d %d %d\n",a,b,c);
            }
        }
    }

    return 0;
}
