#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    int a[4][5],b[2][5];
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            for(i=0;i<2;i++)
                for(j=0;j<5;j++)
                {
                    scanf("%d",&a[i][j]);
                    b[i][j]=a[i][j];
                }
            for(i=2;i<4;i++)
                for(j=0;j<5;j++)
                {
                    scanf("%d",&a[i][j]);
                    if(b[0][j]>=b[1][j])
                    {
                        if(a[i][j]>b[1][j])
                            b[1][j]=a[i][j];
                        //b[1][j]=b[0][j];
                        //b[0][j]=a[i][j];
                    }
                    else
                    {
                        if(a[i][j]>b[0][j])
                        {
                            b[0][j]=b[1][j];
                            b[1][j]=a[i][j];
                        }
                    }
                }
            for(i=0;i<2;i++)
            {
                for(j=0;j<5;j++)
                    printf("%d ",b[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}



/*题意不清导致的错误！
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    int a[4][5],b[2][5];
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            for(j=0;j<5;j++)
            {
                scanf("%d",&a[0][j]);
                b[0][j]=a[0][j];
            }
            for(j=0;j<5;j++)
            {
                scanf("%d",&a[1][j]);
                if(a[1][j]>b[0][j])
                {
                    b[1][j]=b[0][j];
                    b[0][j]=a[1][j];
                }
                else b[1][j]=a[1][j];
            }
            for(i=2;i<4;i++)
                for(j=0;j<5;j++)
                {
                    scanf("%d",&a[i][j]);
                    if(a[i][j]>b[0][j])
                    {
                        b[1][j]=b[0][j];
                        b[0][j]=a[i][j];
                    }
                    else if(a[i][j]>b[1][j])
                        b[1][j]=a[i][j];
                }
            for(i=0;i<2;i++)
            {
                for(j=0;j<5;j++)
                    printf("%d ",b[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}
*/
