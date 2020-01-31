#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void del_dis(char *str,char *s)
{
    int len=strlen(str),l=strlen(s);
    int i,j;
    for(i=0;i<len-l+1;i++)
    {
        for(j=0;j<l;j++)
            if(tolower(str[i+j])!=tolower(s[j]))
                break;
        if(j==l)
        {
            for(j=i;j<len-l;j++)
                str[j]=str[j+l];
            str[j]='\0';
            len-=l;
        }
    }
    for(i=0;str[i]!='\0';i++)
        if(str[i]!=' ')
            printf("%c",str[i]);
    printf("\n");
}
int main()
{
    char s[100];
    char str[1000][1000];
    int n=0,i;
    scanf("%s",s);
    getchar();
    do{
        gets(str[n]);
    }while(str[n++][0]!='}');
    for(i=0;i<n;i++)
        del_dis(str[i],s);
    return 0;
}
