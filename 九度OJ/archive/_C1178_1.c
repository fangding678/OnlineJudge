#include <stdio.h>
#include <stdlib.h>
#define M 1000
int size;
typedef struct Fushu
{
    int a;
    int b;
}Fushu;
void fupop(Fushu *c)
{
    int i,t=0;
    int max=c[0].a*c[0].a+c[0].b*c[0].b;
    for(i=1;i<size;i++)
    {
        if((c[i].a*c[i].a+c[i].b*c[i].b)>max)
        {
            max=c[i].a*c[i].a+c[i].b*c[i].b;
            t=i;
        }
        else if((c[i].a*c[i].a+c[i].b*c[i].b)==max&&c[i].a>c[t].a)
            t=i;
    }
    printf("%d+i%d\n",c[t].a,c[t].b);
    printf("SIZE = %d\n",--size);
    for(i=t;i<size;i++) c[i]=c[i+1];
}
void Insert(Fushu *c,char *s)
{
    int x,y,i;
    x=s[7]-'0';i=8;
    while(s[i]!='+') x=10*x+s[i++]-'0';
    y=s[i+2]-'0';
    while(s[i+3]!='\0') y=y*10+s[i++ +3]-'0';
    c[size].a=x; c[size].b=y;
    size++;
    printf("SIZE = %d\n",size);
}
int main()
{
    int n,i;
    char str[20];
    Fushu d[M];
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        if(n<1||n>M) continue;
        i=0;
        size=0;
        while(i<n)
        {
            gets(str);
            if(str[0]=='P')
            {
                if(size==0) printf("empty\n");
                else fupop(d);
            }
            else if(str[0]=='I')
                Insert(d,str);
            i++;
        }
    }
    return 0;
}
