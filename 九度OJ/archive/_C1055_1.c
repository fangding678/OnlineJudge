#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[201],ch;
    int len,i;
    while(gets(str)!=NULL)
    {
        len=strlen(str);
        for(i=0;i<len/2;i++)
        {
            ch=str[i];
            str[i]=str[len-1-i];
            str[len-1-i]=ch;
        }
        puts(str);
    }
    return 0;
}
