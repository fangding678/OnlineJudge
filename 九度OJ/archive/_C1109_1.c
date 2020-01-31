#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct graph
{
    int v1;
    int v2;
}Graph;
int main()
{
    int n,m;
    Graph *a;
    int i,j,flag;
    int *b;
    while(scanf("%d%d",&n,&m)!=EOF&&n!=0)
    {
        if(n<0||n>1000)
            continue;
        a=(Graph *)malloc(m*sizeof(Graph));
        b=(int *)malloc((n+1)*sizeof(int));
        memset(b,0,(n+1)*sizeof(int));
        flag=0;
        for(i=0;i<m;i++)
            scanf("%d%d",&a[i].v1,&a[i].v2);
        b[a[0].v1]=1;b[a[0].v2]=1;
        for(i=1;i<m;i++)
            for(j=1;j<m;j++)
                if(b[a[j].v1]==1||b[a[j].v2]==1)
                {
                    b[a[j].v1]=1;
                    b[a[j].v2]=1;
                }
        for(i=1;i<=n;i++)
            if(b[i]==0)
            {
                flag=1;
                break;
            }
        if(flag==1)
            printf("NO\n");
        else
            printf("YES\n");
        free(a);
        free(b);
    }
    return 0;
}
