#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[201],ch;
    int i,j,k,len;
    while(gets(str)!=NULL)
    {
        len=strlen(str);
        for(i=0;i<len-1;i++)
        {
            k=i;
            for(j=i+1;j<len;j++)
                if(str[j]<str[k])
                    k=j;
            ch=str[i];
            str[i]=str[k];
            str[k]=ch;
        }
        puts(str);
    }
    return 0;
}
