#include <stdio.h>
#include <stdlib.h>
int isShou(int n)
{
    int i=n*n;
    while(n)
    {
        if(n%10!=i%10) return 0;
        else
        {
            n/=10;
            i/=10;
        }
    }
    return 1;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(isShou(n))
            printf("Yes!\n");
        else
            printf("No!\n");
    }
    return 0;
}
