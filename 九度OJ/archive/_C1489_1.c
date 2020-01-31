#include <stdio.h>

int main()
{
    int a[2][3],b[3][2];
    int i,j,k;
    while(scanf("%d",&a[0][0])!=EOF)
    {
        int c[2][2]={{0,0},{0,0}};
        scanf("%d%d%d%d%d",&a[0][1],&a[0][2],&a[1][0],&a[1][1],&a[1][2]);
        scanf("%d%d%d%d%d%d",&b[0][0],&b[0][1],&b[1][0],&b[1][1],&b[2][0],&b[2][1]);
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<3;k++)
                    c[i][j]+=a[i][k]*b[k][j];
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
    }

    return 0;
}
