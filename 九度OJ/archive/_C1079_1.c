#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 101

int b[26];
void Init()
{
    int i;
    for(i=0;i<18;i++)
        b[i]=i%3+1;
    b[18]=4;
    for(i=19;i<25;i++)
        b[i]=(i-1)%3+1;
    b[25]=4;
}
int main()
{
    int len,result,i;
    char str[M];
    int a[M];
    Init();
    while(gets(str)!=NULL)
    {
        len=strlen(str);
        result=0;
        a[0]=b[str[0]-'a'];
        for(i=1;i<len;i++)
        {
            a[i]=b[str[i]-'a'];
            if((str[i]<'p')&&((str[i-1]-'a')/3==(str[i]-'a')/3))
                a[i]+=2;
            else if((str[i-1]>='p'&&str[i-1]<='s')&&(str[i]>='p'&&str[i]<='s'))
                a[i]+=2;
            else if((str[i-1]>='t'&&str[i-1]<='v')&&(str[i]>='t'&&str[i]<='v'))
                a[i]+=2;
            else if((str[i-1]>='w'&&str[i-1]<='z')&&(str[i]>='w'&&str[i]<='z'))
                a[i]+=2;
        }
        for(i=0;i<len;i++)
            result+=a[i];
        printf("%d\n",result);
    }
    return 0;
}
