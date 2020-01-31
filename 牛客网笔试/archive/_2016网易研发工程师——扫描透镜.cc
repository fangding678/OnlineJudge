#include <iostream>
#include <cstdio>

using namespace std;

int a[22][22];
bool b[22][22];

int Thesum(int p1, int p2, int m)
{
    int i,j,result = 0;
    int x1,y1,x2,y2;
    for(i=0; i<22; ++i)
    {
        for(j=0; j<22; ++j)
        {
            b[i][j] = true;
        }
    }
    x1 = (p1-1)/m + 1;
    y1 = (p1-1)%m + 1;
    x2 = (p2-1)/m + 1;
    y2 = (p2-1)%m + 1;
    for(i=x1-1; i<=x1+1; ++i)
    {
        for(j=y1-1; j<=y1+1; ++j)
        {
            if(a[i][j] > 0)
                result++;
            b[i][j] = false;
        }
    }
    for(i=x2-1; i<=x2+1; ++i)
    {
        for(j=y2-1; j<=y2+1; ++j)
        {
            if((b[i][j] && a[i][j] > 0) || (!b[i][j] && a[i][j] > 1))
                result++;
        }
    }
    return result;
}

int main()
{
    int n,m;
    int i, j, k;
    int ii,jj;
    int result,t;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(i=0; i<22; ++i)
        {
            for(j=0; j<22; ++j)
            {
                a[i][j] = 0;
            }
        }
        for(i=0; i<k; ++i)
        {
            scanf("%d%d",&ii,&jj);
            a[ii][jj]++;
        }
        result = 0;
        for(i=1; i<=n*m; ++i)
        {
            for(j=i+1; j<=n*m; ++j)
            {
                t = Thesum(i, j, m);
                if(result < t)
                    result = t;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}


