#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a[1001][1001],i,j;
    int m,n;
    int startm, startn;
    while(EOF != scanf("%d%d",&m,&n))
    {
        for(i=0; i<m; ++i)
        {
            for(j=0; j<n; ++j)
                scanf("%d",&a[i][j]);
        }
        startm = (m+1)/2;
        startn = (n+1)/2;
        for(i=0; i<startm && i<startn; ++i)
        {
            for(j=i; j<n-i; j++)
                printf("%d ",a[i][j]);
            for(j=i+1; j<m-i; ++j)
                printf("%d ",a[j][n-i-1]);
            for(j=n-i-2; j>=i && m-i-1>i; --j)
                printf("%d ",a[m-i-1][j]);
            for(j=m-i-2; j>i && n-i-1>i; --j)
                printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}

