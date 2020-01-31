#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[1000][16],b[5000][16];
    int n,m;
    int i,j,k,result,count,max;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%s",a[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%s",b[i]);
        if(n==1)
        {
            for(i=0;i<m;i++)
            {
                if(strcmp(a[0],b[i])==0)
                {
                    printf("-1\n");
                    break;
                }
            }
            if(i==m)
                printf("0\n");
            continue;
        }
        count=0;
        result=0;
        max=0;
        while(count<m)
        {
            for(i=0;i<n;i++)
            {
                for(j=count;j<m;j++)
                {
                    if(strcmp(a[i],b[j])==0)
                    {
                        k=j;
                        break;
                    }
                }
                if(j>=m)
                {
                    max=j;
                    result--;
                    break;
                }
                if(k>max)
                    max=k;
            }
            count=max;
            result++;
        }
        printf("%d\n",result);
    }
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[1000][16],b[5000][16],c[1000];
    int n,m;
    int i,j,k,result,count;
    while(~scanf("%d",&n))
    {
        result=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",a[i]);
            c[i]=0;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%s",b[i]);
        count=0;
        if(n==1)
        {
            for(i=0;i<m;i++)
                if(strcmp(a[0],b[i])==0)
                {
                    printf("-1\n");
                    break;
                }
            continue;
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(strcmp(b[i],a[j])==0)
                {
                    if(c[j]==1)
                        break;
                    count++;
                    c[j]=1;
                    k=j;
                    break;
                }
            }
            if(count==n)
            {
                result++;
                count=1;
                for(i=0;i<n;i++)
                    c[i]=0;
                c[k]=1;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
typedef struct IP
{
    int x,y,z,w;
    int flag;
}IP;
int equal(IP c,IP d)
{
    if(c.w==d.w&&c.x==d.x&&c.y==d.y&&c.z==d.z)
        return 1;
    return 0;
}
int main()
{
    IP a[1000],b[5000];
    int n,m;
    int i,j,k,result,count;
    while(~scanf("%d",&n))
    {
        result=0;
        for(i=0;i<n;i++)
        {
            scanf("%d.%d.%d.%d",&a[i].x,&a[i].y,&a[i].z,&a[i].w);
            a[i].flag=0;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d.%d.%d.%d",&b[i].x,&b[i].y,&b[i].z,&b[i].w);
        count=0;
        if(n==1)
        {
            for(i=0;i<m;i++)
                if(equal(a[0],b[i]))
                {
                    printf("-1\n");
                    continue;
                }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(equal(b[i],a[j])&&a[j].flag==0)
                {
                    count++;
                    a[j].flag=1;
                    k=j;
                }
            }
            if(count==n)
            {
                result++;
                count=1;
                for(i=0;i<n;i++)
                    a[i].flag=0;
                a[k].flag=1;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
*/
