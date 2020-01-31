#include <stdio.h>
#include <stdlib.h>
int c[10][10];
void Chengji(int **a,int n,int k)
{
    int **b;
    int x,y,z,t;
    b=(int **)malloc(n*sizeof(int *));
    for(x=0;x<n;x++)
        b[x]=(int *)malloc(n*sizeof(int));
    for(x=0;x<n;x++)
        for(y=0;y<n;y++)
            if(x!=y) b[x][y]=0;
            else b[x][y]=1;
    for(y=0;y<n;y++)
        for(z=0;z<n;z++)
            c[y][z]=0;
    for(x=0;x<k;x++)
    {
        for(y=0;y<n;y++)
            for(z=0;z<n;z++)
                for(t=0;t<n;t++)
                    c[y][z]+=a[y][t]*b[t][z];
        for(y=0;y<n;y++)
            for(z=0;z<n;z++)
            {
                b[y][z]=c[y][z];
                c[y][z]=0;
            }
    }
    for(x=0;x<n;x++)
        for(y=0;y<n;y++)
            a[x][y]=b[x][y];
    for(x=0;x<n;x++)
        free(b[x]);
    free(b);
}
int main()
{
    int t;
    int n,k;
    int x,y,z;
    int c[10];
    int ***a;
    while(scanf("%d",&t)!=EOF)
    {
        a=(int ***)malloc(t*sizeof(int **));
        for(x=0;x<t;x++)
        {
            scanf("%d%d",&n,&k);
            a[x]=(int **)malloc(n*sizeof(int *));
            c[x]=n;
            for(y=0;y<n;y++)
            {
                a[x][y]=(int *)malloc(n*sizeof(int));
                for(z=0;z<n;z++)
                    scanf("%d",&a[x][y][z]);
            }
            Chengji(a[x],n,k);
        }
        for(x=0;x<t;x++)
            for(y=0;y<c[x];y++)
            {
                for(z=0;z<c[x]-1;z++)
                    printf("%d ",a[x][y][z]);
                printf("%d\n",a[x][y][z]);
            }
        for(x=0;x<t;x++)
            for(y=0;y<n;y++)
                free(a[x][y]);
        for(x=0;x<t;x++)
            free(a[x]);
        free(a);
    }
    return 0;
}
