#include <stdio.h>
#include <stdlib.h>
typedef struct Grade
{
    int GE;
    int GI;
    int **a;
    int flag;
    int rank;
}Grade;
int main()
{
    int N,M,K;
    int i,j,k;
    while(scanf("%d%d%d",&N,&M,&K)!=EOF)
    {
        if(N<1||N>4000||M<1||M>100||K<1||K>5)
            continue;
        Grade *G=(Grade *)malloc(N*sizeof(Grade));
        int *b,*c;
        G->a=(int **)malloc(N*sizeof(int *));
        b=(int *)malloc(M*sizeof(int));
        c=(int *)malloc(N*sizeof(int));
        for(i=0;i<M;i++)
            scanf("%d",&b[i]);
        for(i=0;i<N;i++)
            G->a[i]=(int *)malloc(K*sizeof(int));
        for(i=0;i<N;i++)
        {
            scanf("%d%d%d%d%d",&G[i].GE,&G[i].GI,&G[i].a[i][0],&G[i].a[i][1],&G[i].a[i][2]);
            G->flag=0;
            c[i]=0;
        }
        for(i=0;i<N;i++)
        {
            max_1=G[i].GE;
            max_2=G[i].GI;
            for(j=0;j<N;j++)
            {
                if(G->flag==1)
                continue;
                else
                {
                    if(G[j].GE>max_1)
                       {
                           max_1=G[j].GE;
                           max_2=G[J].GI;
                       }
                    else if(G[j].GE==max_1)
                }
            }
        }
    }

    return 0;
}
