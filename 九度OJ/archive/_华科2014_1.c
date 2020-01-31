#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int a[10001];
void Init(int n)
{
    int i,j;
    int m=sqrt(n);
    for(i=2;i<=m;i++)
    {
        for(j=i*i;j<n;j+=i)
            a[j]=1;
    }
}
int main()
{
    int i,k;
    memset(a,0,sizeof(a));
    Init(10000);
    int x,y,z,w;
    i=2000;k=0;
    while(i<10000)
    {
        x=i/1000;
        if(x%2==0&&x!=2)
        {
            i+=1000;
            x++;
        }
        y=i/100;
        if(y%2==0)
        {
            i+=100;
            y++;
        }
        z=i/10;
        if(z%2==0)
        {
            i+=10;
            z++;
        }
        w=i;
        if(w%2==0)
        {
            i++;
            w++;
        }
        if(a[x]==0&&a[y]==0&&a[z]==0&&a[w]==0)
        {
            k++;
            if(k%6!=0) printf("%d ",i);
            else printf("%d\n",i);
        }
        i++;
    }
    return 0;
}
