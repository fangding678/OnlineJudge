#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[101],s2[101],s[201];
    int len1,len2,i,j,k;
    while(gets(s1)!=NULL)
    {
        gets(s2);
        len1=strlen(s1);
        len2=strlen(s2);
        k=0;
        for(i=0,j=len2-1;i<len1||j>=0;i++,j--)
        {
            if(i<len1)
                s[k++]=s1[i];
            if(j>=0)
                s[k++]=s2[j];
        }
        s[k]='\0';
        puts(s);
    }
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s1[101],s2[101],s[201];
    int len1,len2,i,j,k;
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        len1=strlen(s1);
        len2=strlen(s2);
        k=0;
        for(i=0,j=len2-1;i<len1||j>=0;i++,j--)
        {
            if(i<len1)
                s[k++]=s1[i];
            if(j>=0)
                s[k++]=s2[j];
        }
        s[k]='\0';
        for(i=0;s[i]!='\0';i++)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
*/
