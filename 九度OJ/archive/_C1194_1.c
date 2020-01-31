#include <stdio.h>
#include <stdlib.h>

void Tran_8(int n)
{
    if(n>0)
    {
        Tran_8(n/8);
        printf("%d",n%8);
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n<0||n>100000) continue;
        if(n>0) Tran_8(n);
        else printf("0");
        printf("\n");
    }
    return 0;
}
