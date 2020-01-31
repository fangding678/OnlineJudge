#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10001

int a[N];
void Init()
{
    int i,j;
    for(i=2;i<=100;i++)
        for(j=i*i;j<N;j+=i)
            a[j]=1;
}
int main()
{
    int m,i,k;
    int b[N];
    while(~scanf("%d",&m))
    {
        if(m<5||m>10000) continue;
        memset(a,0,N*sizeof(int));
        Init();
        k=0;
        for(i=2;i<N;i++)
            if(a[i]==0) b[k++]=i;
        while(b[--k]>m);
        for(i=k;i>1;i--)
            if((b[i]-b[i-1])==2) break;
        printf("%d,%d\n",b[i-1],b[i]);
    }
    return 0;
}
