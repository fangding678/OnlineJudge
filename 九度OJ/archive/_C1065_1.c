#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,i,j;
    while(~scanf("%d",&h))
    {
        for(i=0;i<h;i++)
        {
            for(j=0;j<h-i-1;j++)
                printf("  ");
            for(j=0;j<h+2*i;j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
