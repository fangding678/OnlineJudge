/*网上参考代码
#include<stdio.h>
#include<string.h>

int main(){
int t,i,j,k,len,m;
int b[500];
char a[500];

i=0;
scanf("%d",&m);
gets(a);

k=1;
while(m--){
gets(a);
len = strlen(a);
j=0;
i=0;
while (i<len)
{
 if(a[i]!=' ')
  {
  if (a[i]>='0' && a[i]<='9')
   b[j++]=a[i]-'0';
  else
   b[j++]=a[i]-'a'+10;
  }
 i++;
}

printf("Case #%d\nTotal length = %d bytes\n",k++,b[4]*16*16*16+b[5]*16*16+b[6]*16+b[7]);
printf("Source = %d.%d.%d.%d\n",b[24]*16+b[25],b[26]*16+b[27],b[28]*16+b[29],b[30]*16+b[31]);
printf("Destination = %d.%d.%d.%d\n",b[32]*16+b[33],b[34]*16+b[35],b[36]*16+b[37],b[38]*16+b[39]);
t=b[1]*8;
printf("Source Port = %d\n",b[t]*16*16*16+b[t+1]*16*16+b[t+2]*16+b[t+3]);
printf("Destination Port = %d\n\n",b[t+4]*16*16*16+b[t+5]*16*16+b[t+6]*16+b[t+7]);

}
}
*/

//一组测试可以通过
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct IP
{
    int a;
    int b;
    int c;
    int d;
}IP;
typedef struct S
{
    int len;
    IP source;
    IP destination;
    int source_port;
    int destinstion_port;
}S;
int tran(char e)
{
    if(e>='0'&&e<='9') return e-'0';
    else if(e>='a'&&e<='z') return e-'a'+10;
    return 0;
}
int main()
{
    int n,i;
    char str[500];
    S Node;
    int x;
    scanf("%d",&n);
    gets(str);
    i=1;
    while(n--)
    {
            gets(str);
            x=4*tran(str[1]);
            Node.len=16*256*tran(str[6])+256*tran(str[7])+\
            16*tran(str[9])+tran(str[10]);
            Node.source.a=tran(str[36])*16+tran(str[37]);
            Node.source.b=tran(str[39])*16+tran(str[40]);
            Node.source.c=tran(str[42])*16+tran(str[43]);
            Node.source.d=tran(str[45])*16+tran(str[46]);
            Node.destination.a=tran(str[48])*16+tran(str[49]);
            Node.destination.b=tran(str[51])*16+tran(str[52]);
            Node.destination.c=tran(str[54])*16+tran(str[55]);
            Node.destination.d=tran(str[57])*16+tran(str[58]);
            Node.source_port=4096*tran(str[3*x])+256*tran(str[3*x+1])+\
            16*tran(str[3*x+3])+tran(str[3*x+4]);
            Node.destinstion_port=4096*tran(str[3*x+6])+256*tran(str[3*x+7])+\
            16*tran(str[3*x+9])+tran(str[3*x+10]);

            printf("Case #%d\n",i++);
            printf("Total length = %d bytes\n",Node.len);
            printf("Source = %d.%d.%d.%d\n",Node.source.a,\
                   Node.source.b,Node.source.c,Node.source.d);
            printf("Destination = %d.%d.%d.%d\n",Node.destination.a,\
                   Node.destination.b,Node.destination.c,Node.destination.d);
            printf("Source Port = %d\n",Node.source_port);
            printf("Destination Port = %d\n\n",Node.destinstion_port);
    }
    return 0;
}


/*多组测试但是不能通过
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SString
{
    char e[400];
}SString;
typedef struct IP
{
    int a;
    int b;
    int c;
    int d;
}IP;
typedef struct S
{
    int len;
    IP source;
    IP destination;
    int source_port;
    int destinstion_port;
}S;
int tran(char e)
{
    if(e>='0'&&e<='9') return e-'0';
    else if(e>='a'&&e<='z') return e-'a'+10;
    return 0;
}
int main()
{
    int n,i;
    SString *str;
    S *Node;
    int x;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        str=(SString *)malloc(n*sizeof(SString));
        Node=(S *)malloc(n*sizeof(S));
        for(i=0;i<n;i++)
            gets(str[i].e);
        for(i=0;i<n;i++)
        {
            x=4*tran(str[i].e[1]);
            Node[i].len=16*256*tran(str[i].e[6])+256*tran(str[i].e[7])+\
            16*tran(str[i].e[9])+tran(str[i].e[10]);
            Node[i].source.a=tran(str[i].e[36])*16+tran(str[i].e[37]);
            Node[i].source.b=tran(str[i].e[39])*16+tran(str[i].e[40]);
            Node[i].source.c=tran(str[i].e[42])*16+tran(str[i].e[43]);
            Node[i].source.d=tran(str[i].e[45])*16+tran(str[i].e[46]);
            Node[i].destination.a=tran(str[i].e[48])*16+tran(str[i].e[49]);
            Node[i].destination.b=tran(str[i].e[51])*16+tran(str[i].e[52]);
            Node[i].destination.c=tran(str[i].e[54])*16+tran(str[i].e[55]);
            Node[i].destination.d=tran(str[i].e[57])*16+tran(str[i].e[58]);
            Node[i].source_port=4096*tran(str[i].e[3*x])+256*tran(str[i].e[3*x+1])+\
            16*tran(str[i].e[3*x+3])+tran(str[i].e[3*x+4]);
            Node[i].destinstion_port=4096*tran(str[i].e[3*x+6])+256*tran(str[i].e[3*x+7])+\
            16*tran(str[i].e[3*x+9])+tran(str[i].e[3*x+10]);
        }
        for(i=0;i<n;i++)
        {
            printf("Case #%d\n",i+1);
            printf("Total length = %d bytes\n",Node[i].len);
            printf("Source = %d.%d.%d.%d\n",Node[i].source.a,\
                   Node[i].source.b,Node[i].source.c,Node[i].source.d);
            printf("Destination = %d.%d.%d.%d\n",Node[i].destination.a,\
                   Node[i].destination.b,Node[i].destination.c,Node[i].destination.d);
            printf("Source Port = %d\n",Node[i].source_port);
            printf("Destination Port = %d\n\n",Node[i].destinstion_port);
        }
        free(str);
        free(Node);
    }
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SString
{
    char *e;
}SString;
typedef struct IP
{
    int a;
    int b;
    int c;
    int d;
}IP;
typedef struct S
{
    int len;
    IP source;
    IP destination;
    int source_port;
    int destinstion_port;
}S;
int tran(char e)
{
    if(e>='0'&&e<='9') return e-'0';
    else if(e>='a'&&e<='f') return e-'a'+10;
    else if(e>='A'&&e<='F') return e-'A'+10;
    return 0;
}
int main()
{
    int n,i;
    SString *str;
    S *Node;
    int x;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        str=(SString *)malloc(n*sizeof(SString));
        Node=(S *)malloc(n*sizeof(S));
        //for(i=0;i<n;i++)
          //  gets(str[i].e);
        //str.e="45 00 00 34 7a 67 40 00 40 06 63 5a 0a cd 0a f4 7d 38 ca \
        09 cd f6 00 50 b4 d7 ae 1c 9b cf f2 40 80 10 ff 3d fd d0 00 00 01 01 \
        08 0a 32 53 7d fb 5e 49 4e c8";
        str->e="45 00 00 c6 56 5a 40 00 34 06 e0 45 cb d0 2e 01 0a cd 0a f4 \
        00 50 ce 61 e1 e9 b9 ee 47 c7 37 34 80 18 00 b5 81 8f 00 00 01 01 08 \
        0a 88 24 fa c6 32 63 cd 8d";
        for(i=0;i<n;i++)
        {
            x=4*tran(str[i].e[1]);
            Node[i].len=16*256*tran(str[i].e[6])+256*tran(str[i].e[7])+\
            16*tran(str[i].e[9])+tran(str[i].e[10]);
            Node[i].source.a=tran(str[i].e[36])*16+tran(str[i].e[37]);
            Node[i].source.b=tran(str[i].e[39])*16+tran(str[i].e[40]);
            Node[i].source.c=tran(str[i].e[42])*16+tran(str[i].e[43]);
            Node[i].source.d=tran(str[i].e[45])*16+tran(str[i].e[46]);
            Node[i].destination.a=tran(str[i].e[48])*16+tran(str[i].e[49]);
            Node[i].destination.b=tran(str[i].e[51])*16+tran(str[i].e[52]);
            Node[i].destination.c=tran(str[i].e[54])*16+tran(str[i].e[55]);
            Node[i].destination.d=tran(str[i].e[57])*16+tran(str[i].e[58]);
            Node[i].source_port=4096*tran(str[i].e[3*x])+256*tran(str[i].e[3*x+1])+\
            16*tran(str[i].e[3*x+3])+tran(str[i].e[3*x+4]);
            Node[i].destinstion_port=4096*tran(str[i].e[3*x+6])+256*tran(str[i].e[3*x+7])+\
            16*tran(str[i].e[3*x+9])+tran(str[i].e[3*x+10]);
        }
        for(i=0;i<n;i++)
        {
            printf("Case #%d\n",i+1);
            printf("Total length = %d bytes\n",Node[i].len);
            printf("Source = %d.%d.%d.%d\n",Node[i].source.a,\
                   Node[i].source.b,Node[i].source.c,Node[i].source.d);
            printf("Destination = %d.%d.%d.%d\n",Node[i].destination.a,\
                   Node[i].destination.b,Node[i].destination.c,Node[i].destination.d);
            printf("Source Port = %d\n",Node[i].source_port);
            printf("Destination Port = %d\n\n",Node[i].destinstion_port);
        }
    }
    return 0;
}
*/
