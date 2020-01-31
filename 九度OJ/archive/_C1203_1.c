#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLegal(char *str,int len)
{
    int i,n;
    char *s=str;
    if(len>15||len<7) return 0;
    for(i=0;i<4;i++)
    {
        n=0;
        while(*s!='.'&&*s!='\0')
        {
            n=n*10+*s-'0';
            s++;
        }
        s++;
        if(n<0||n>255) return 0;
    }
    return 1;
}
int main()
{
    int n,i,len;
    char str[20];
    int *a;
    while(~scanf("%d",&n))
    {
        a=(int *)calloc(n,sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            len=strlen(str);
            a[i]=isLegal(str,len);
        }
        for(i=0;i<n;i++)
        {
            if(a[i]) printf("Yes!\n");
            else printf("No!\n");
        }
        free(a);
    }
    return 0;
}
