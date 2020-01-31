#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[210],s[110];
    int i,j;
    while(~scanf("%s%s",str,s))
    {
        i=0;j=0;
        while(str[i]!='\0') i++;
        while(s[j]!='\0') str[i++]=s[j++];
        str[i]='\0';
        printf("%s\n",str);
    }
    return 0;
}
