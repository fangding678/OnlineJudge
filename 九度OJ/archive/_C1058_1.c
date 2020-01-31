#include <stdio.h>
#include <stdlib.h>

int main()
{
    char e,str[5];
    while(gets(str)!=NULL)
    {
        e=str[0];
        str[0]=str[3];
        str[3]=e;
        e=str[1];
        str[1]=str[2];
        str[2]=e;
        puts(str);
    }
    return 0;
}
