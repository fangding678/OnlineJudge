
#include <stdio.h>
#include <stdlib.h>
typedef struct guojia
{
     int gold;
     int prize;
     int population;
}node;
typedef struct shu
{
    int m_c;
    int way;
}result;

result sort(node *,int,int);
void input(node *,int);
void output(result *,int);

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        node *a=(node *)malloc(sizeof(node)*n);
        node *d=(node *)malloc(sizeof(node)*m);
        result *b=(result *)malloc(sizeof(result)*m);
        int *c=(int *)malloc(sizeof(int)*m);
        int i;
        input(a,n);
        for(i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
            d[i]=a[c[i]];
        }
        for(i=0;i<m;i++)
            b[i]=sort(d,i,m);
        output(b,m);
    }
    return 0;
}
void input(node d[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i].gold);
        scanf("%d",&d[i].prize);
        scanf("%d",&d[i].population);
    }
}
result sort(node *a,int num,int n)
{
    result temp;
    int i,n1=1,n2=1,n3=1,n4=1;
    for(i=0;i<n;i++)
    {
        if(a[i].gold>a[num].gold) n4++;
        if(a[i].prize>a[num].prize) n3++;
        if(a[i].gold*a[num].population>a[num].gold*a[i].population) n2++;
        if(a[i].prize*a[num].population>a[num].prize*a[i].population) n1++;
    }
    if(n4<=n3&&n4<=n2&&n4<=n1)
    {
        temp.m_c=n4;
        temp.way=1;
    }
    else if(n3<n4&&n3<=n2&&n3<=n1)
    {
        temp.m_c=n3;
        temp.way=2;
    }
    else if(n2<n4&&n2<n3&&n2<=n1)
    {
        temp.m_c=n2;
        temp.way=3;
    }
    else
    {
        temp.m_c=n1;
        temp.way=4;
    }
    return temp;
}
void output(result *b,int m)
{
    int i;
    for(i=0;i<m;i++)
        printf("%d:%d\n",b[i].m_c,b[i].way);
    printf("\n");
}

//本代码测试没错误。但提交有错！
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct guojia
{
     int gold;
     int prize;
     int population;
}node;
typedef struct shu
{
    int m_c;
    int way;
}result;

result sort(node *,int,int);
void input(node *,int);
void output(result *,int);

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        node a[n],d[m];
        result b[m];
        int c[m],i;
        input(a,n);
        for(i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
            d[i]=a[c[i]];
        }
        for(i=0;i<m;i++)
            b[i]=sort(d,c[i],m);
        output(b,m);
    }
    return 0;
}
void input(node d[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i].gold);
        scanf("%d",&d[i].prize);
        scanf("%d",&d[i].population);
    }
}
result sort(node *a,int num,int n)
{
    result temp;
    int i,n1=1,n2=1,n3=1,n4=1;
    for(i=0;i<n;i++)
    {
        if(a[i].gold>a[num].gold) n4++;
        if(a[i].prize>a[num].prize) n3++;
        if(a[i].gold*a[num].population>a[num].gold*a[i].population) n2++;
        if(a[i].prize*a[num].population>a[num].prize*a[i].population) n1++;
    }
    if(n4<=n3&&n4<=n2&&n4<=n1)
    {
        temp.m_c=n4;
        temp.way=1;
    }
    else if(n3<n4&&n3<=n2&&n3<=n1)
    {
        temp.m_c=n3;
        temp.way=2;
    }
    else if(n2<n4&&n2<n3&&n2<=n1)
    {
        temp.m_c=n2;
        temp.way=3;
    }
    else
    {
        temp.m_c=n1;
        temp.way=4;
    }
    return temp;
}
void output(result *b,int m)
{
    int i;
    for(i=0;i<m;i++)
        printf("%d:%d\n",b[i].m_c,b[i].way);
    printf("\n");
}
*/

/*本代码测试没错误。但对题目的意思理解不正确！
#include <stdio.h>
#include <stdlib.h>
typedef struct guojia
{
     int gold;
     int prize;
     int population;
}node;
typedef struct shu
{
    int m_c;
    int way;
}result;

result sort(node *,int,int);
void input(node *,int);
void output(result *,int);

int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF&&scanf("%d",&m))
    {
        node a[n];
        result b[m];
        int c[m],i;
        input(a,n);
        for(i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
        }
        for(i=0;i<m;i++)
            b[i]=sort(a,c[i],m);
        output(b,m);
    }
    return 0;
}
void input(node d[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i].gold);
        scanf("%d",&d[i].prize);
        scanf("%d",&d[i].population);
    }
}
result sort(node *a,int num,int n)
{
    result temp;
    int i,n1=1,n2=1,n3=1,n4=1;
    float m1,m2,m3,m4;
    for(i=0;i<n;i++)
    {
        m1=((float)a[i].gold)/(float)(a[i].population);
        m2=((float)a[num].gold)/(float)(a[num].population);
        m3=((float)a[i].prize)/(float)(a[i].population);
        m4=((float)a[num].prize)/(float)(a[num].population);
        if(a[i].gold>a[num].gold) n4++;
        if(a[i].prize>a[num].prize) n3++;
        if(m1>m2) n2++;
        if(m3>m4) n1++;
    }
    if(n4<=n3&&n4<=n2&&n4<=n1)
    {
        temp.m_c=n4;
        temp.way=1;
    }
    else if(n3<n4&&n3<=n2&&n3<=n1)
    {
        temp.m_c=n3;
        temp.way=2;
    }
    else if(n2<n4&&n2<n3&&n2<=n1)
    {
        temp.m_c=n2;
        temp.way=3;
    }
    else
    {
        temp.m_c=n1;
        temp.way=4;
    }
    return temp;
}
void output(result *b,int m)
{
    int i;
    for(i=0;i<m;i++)
        printf("%d:%d\n",b[i].m_c,b[i].way);
    printf("\n");
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
typedef struct guojia
{
     int gold;
     int prize;
     int population;
}node;
void input(node *,int);
void sort(node *,int *,int);
void sort_1(node *,int);
void sort_2(node *,int);
void sort_3(node *,int);
void sort_4(node *,int);
void print(node *,int *);

int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF&&scanf("%d",&m))
    {
        node a[n];
        int b[m],i;
        input(a,n);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        sort(a,b);
        print(a,b);
    }
    return 0;
}
void input(node d[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i].gold);
        scanf("%d",&d[i].prize);
        scanf("%d",&d[i].population);
    }
}
void sort_1(node *d,int num)
{
    int i,j,k;
    node temp;
    for(i=0;i<num;i++)
    {
        k=i;
        for(j=i+1;j<num;j++)
            if(d[k].gold<d[j].gold)
            k=j;
        temp=d[i];
        d[i]=d[k]
        d[k]=temp;
    }
}
void sort_2(node *d,int num)
{
    int i,j,k;
    node temp;
    for(i=0;i<num;i++)
    {
        k=i;
        for(j=i+1;j<num;j++)
            if(d[k].prize<d[j].prize)
            k=j;
        temp=d[i];
        d[i]=d[k]
        d[k]=temp;
    }
}
void sort_3(node *d,int num)
{
    int i,j,k;
    float a,b;
    node temp;
    for(i=0;i<num;i++)
    {
        k=i;
        for(j=i+1;j<num;j++)
        {
            a=((float)d[k].gold)/((float)(d[k].population));
            b=((float)d[j].gold)/((float)(d[j].population));
            if(a<b)
            k=j;
        }
        temp=d[i];
        d[i]=d[k]
        d[k]=temp;
    }
}
void sort_4(node *d,int num)
{
    int i,j,k;
    float a,b;
    node temp;
    for(i=0;i<num;i++)
    {
        k=i;
        for(j=i+1;j<num;j++)
            {
                a=((float)d[k].prize)/((float)d[k].population);
                b=((float)d[j].prize)/((float)d[j].population);
                if(a<b)
                k=j;
            }
        temp=d[i];
        d[i]=d[k]
        d[k]=temp;
    }
}
void sort(node *d,int *arr,int num)
{
    int i;

    for(i=0;i<num;i++)
    {
        s
    }
}

void print(node *d,int *arr)
{
    int
}
*/

