#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[81];
    int i;
    while(gets(str)!=NULL)
    {
        if(strcmp(str,"!")==0)
            break;
        for(i=0;str[i]!='\0';i++)
        {
            if(str[i]>='a'&&str[i]<='z')
                str[i]='a'+'z'-str[i];
            else if(str[i]>='A'&&str[i]<='Z')
                str[i]='A'+'Z'-str[i];
        }
        puts(str);
    }
    return 0;
}
