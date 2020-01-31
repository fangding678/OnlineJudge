#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int pipei(char *st,char *s,int len,int len1,int len2)
{
    int i,flag=0;
    int l=strlen(st);
    if((len+len1-len2)!=l)
        return 0;
    for(i=0;i<len1;i++)
        if(tolower(st[i])!=tolower(s[i]))
            return 0;
    for(i=len-1;i>len2;i--)
        if(tolower(st[--l])!=tolower(s[i]))
            return 0;
    for(i=len1+1;i<len2;i++)
        if(tolower(st[len1])==tolower(s[i]))
        {
            flag=1;
            break;
        }
    if(flag==0)
        return 0;
    return 1;
}
int main()
{
    int n,i,len,len1,len2;
    char str[1000][1000];
    char s[1000];
    while(~scanf("%d",&n))
    {
        if(n<1||n>1000)
            continue;
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        scanf("%s",s);
        len=strlen(s);
        len1=-1;len2=len;
        while(s[++len1]!='[');
        while(s[--len2]!=']');
        for(i=0;i<n;i++)
            if(pipei(str[i],s,len,len1,len2))
                printf("%d %s\n",(i+1),str[i]);
    }
    return 0;
}




