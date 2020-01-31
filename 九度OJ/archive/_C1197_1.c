#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[8];
int n;
void Jiaoyan(char c)
{
    int x=c;
    n=0;
    int sum=0;
    memset(a,0,8*sizeof(int));
    while(x)
    {
        a[n++]=x%2;
        sum+=x%2;
        x/=2;
    }
    if((sum&1)==1) a[7]=0;
    else a[7]=1;
    for(x=7;x>=0;x--)
        printf("%d",a[x]);
    printf("\n");
}
int main()
{
    char str[101];
    int i,len;
    while(gets(str)!=NULL)
    {
        len=strlen(str);
        for(i=0;i<len;i++)
            Jiaoyan(str[i]);
    }
    return 0;
}
