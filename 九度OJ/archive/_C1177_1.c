#include <stdio.h>
#include <stdlib.h>
void Reverse(char *str,int low,int high)
{
    char e;
    while(low<high)
    {
        e=str[low];
        str[low]=str[high];
        str[high]=e;
        low++;
        high--;
    }
}
void Replace(char *s1,int n,int m,char *s2)
{
    int i;
    for(i=0;i<m;i++)
        s1[n++]=s2[i];
}

int main()
{
    int n,i;
    char str[101],s[101];
    while(gets(str)!=NULL)
    {
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='0')
                Reverse(str,s[1]-'0',s[2]+s[1]-'1'-'0');
            else if(s[0]=='1')
                Replace(str,s[1]-'0',s[2]-'0',&s[3]);
            puts(str);
        }
        getchar();
    }
    return 0;
}
