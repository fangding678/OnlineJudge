#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1001
int cmp(const void *a,const void *b)
{
    int i,len_a,len_b;
    len_a=strlen((char *)a);
    len_b=strlen((char *)b);
    if(len_a!=len_b)
        return len_a-len_b;
    for(i=0;i<len_a-1;i++)
    {
        if(((char *)a)[i]!=((char *)b)[i])
            return ((char *)a)[i]-((char *)b)[i];
    }
    return ((char *)a)[i]-((char *)b)[i];
}
int main()
{
    char str[101][M];
    int i,n;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        qsort(str,n,M*sizeof(char),cmp);
        for(i=0;i<n;i++)
            printf("%s\n",str[i]);
    }
    return 0;
}
