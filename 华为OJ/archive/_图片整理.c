#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[1025],ch;
    int i,j,len;
    while(gets(str)!=NULL)
    {
        len=strlen(str);
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(str[j]<str[i])
                {
                    ch=str[i];
                    str[i]=str[j];
                    str[j]=ch;
                }
            }
        }
        printf("%s\n",str);
    }
    return 0;
}
