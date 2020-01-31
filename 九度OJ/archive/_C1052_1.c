#include <stdio.h>
int main()
{
    int n,i;
    int a[200];
    while(scanf("%d",&n)!=EOF)
    {
        int m;
        if(n<1||n>200)
            continue;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=0;i<n;i++)
            if(a[i]==m)
            break;
        if(i==n)
            printf("-1\n");
        else
            printf("%d\n",i);
    }
    return 0;
}
