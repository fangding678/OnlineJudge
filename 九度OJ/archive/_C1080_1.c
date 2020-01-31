#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define M 1001
int len;
int isEmpty(int *a)
{
    int i=len-1;
    while(a[i]==0) i--;
    if(i<0) return 1;
    return 0;
}
int Divide_Mod(int *a,int m,int n)
{
    int i;
    int mod=0;
    for(i=0;i<len;i++)
    {
        a[i]+=mod*m;
        mod=a[i]%n;
        a[i]/=n;
    }
    return mod;
}

void Reverse_Output(int *a,int *b,int m,int n)
{
    int i=0;
    char c;
    while(!isEmpty(a))
        b[i++]=Divide_Mod(a,m,n);
    while(i)
    {
        if(b[i-1]<=9&&b[i-1]>=0)
            c=b[i-1]+'0';
        else
            c=b[i-1]+'a'-10;
        i--;
        printf("%c",c);
    }
}

int main()
{
    int n,m,i;
    char str[M];
    int a[M],b[M];
    while(~scanf("%d%d%s",&m,&n,str))
    {
        if(n<2||m<2||n>36||m>36)
            continue;
        len=strlen(str);
        if(str[0]=='-')
        {
            i=1;
            printf("-");
            a[0]=0;
        }
        else
            i=0;
        if(len-i==1&&str[i]=='0')
            printf("0");
        while(i<len)
        {
            if(str[i]>='0'&&str[i]<='9')
                a[i]=str[i]-'0';
            else
                a[i]=str[i]-'A'+10;
            i++;
        }
        Reverse_Output(a,b,m,n);
        printf("\n");
    }
    return 0;
}

