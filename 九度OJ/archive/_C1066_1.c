#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    return *(char *)a-*(char *)b;
}
int main()
{
    char str[21];
    int len;
    while(gets(str)!=NULL)
    {
        len=strlen(str);
        qsort(str,len,sizeof(char),cmp);
        puts(str);
    }
    return 0;
}
