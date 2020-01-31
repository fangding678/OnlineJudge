#include <stdio.h>
#include <stdlib.h>

short Tran_1(char *str)
{
    short n=0,i=0;
    while(str[i]!='\0')
        n=(str[i++]-'0')+n*2;
    return n;
}
short yunsuan(short a,short b,char e)
{
    if(e=='+') return a+b;
    else if(e=='-') return a-b;
    else if(e=='*') return a*b;
    else return a/b;
}
void output(short c)
{
    if(c>0)
    {
        output(c/2);
        if((c&1)==1) printf("1");
        else printf("0");
    }
}
int main()
{
    char e;
    char str1[20],str2[20];
    short a,b,c;
    while(~scanf("%s%s",str1,str2))
    {
        e=getchar();
        while(e==' ')
            e=getchar();
        a=Tran_1(str1);
        b=Tran_1(str2);
        c=yunsuan(a,b,e);
        output(c);
        printf("\n");
    }
    return 0;
}
