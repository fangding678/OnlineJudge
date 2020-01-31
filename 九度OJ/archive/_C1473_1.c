#include <stdio.h>
#include <stdlib.h>
void Reverse(int n)
{
    if(n==0)
        printf("0");
    else if(n==1)
        printf("1");
    else
    {
        Reverse(n>>1);
        printf("%d",n%2);
    }
}
int main()
{
    int n,i;
    int *a;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<1||n>1000)
            continue;
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            Reverse(a[i]);
            printf("\n");
        }
        free(a);
    }
    return 0;
}
