#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define M 1001

typedef struct SS
{
    char s[1001];
    int len;
}SS;
int main()
{
    SS str[1000];
    int n=0,i;
    int len_min=M,len_max=0;
    while(gets(str[n].s)!=NULL)
    {
        str[n].len=strlen(str[n].s);
        if(str[n].len>len_max) len_max=str[n].len;
        if(str[n].len<len_min) len_min=str[n].len;
        n++;
    }
    for(i=0;i<n;i++)
        if(str[i].len==len_min)
            printf("%s\n",str[i].s);
    for(i=0;i<n;i++)
        if(str[i].len==len_max)
            printf("%s\n",str[i].s);
    return 0;
}
