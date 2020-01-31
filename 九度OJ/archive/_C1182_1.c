#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,k,a[10010];
    char str[10010];
    while(gets(str)!=NULL)
    {
        memset(a,0,sizeof(a));
        i=0;k=0;
        while(str[i]!='.')
        {
            if(str[i]!=' ') a[k]++;
            else if(str[i]==' '&&str[i+1]!=' ') k++;
            i++;
        }
        for(i=0;i<k;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[k]);
    }
    return 0;
}
