#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][100];
int k;
int result;

int isMin(int a, int b, int c, int d)
{
    int t = 0;
    for(int i=a; i<c; ++i)
    {
        for(int j=b; j<d; ++j)
        {
            t = t + arr[i][j];
        }
    }
    return t;
}


int main()
{
    int n,m;
    int i,j,ii,jj,tt;
    while(cin>>n>>m>>k)
    {
        result = 10001;
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                cin>>arr[i][j];
                if(arr[i][j] >= k)
                {
                    result = 1;
                }
            }
        }
        if(result != 10001)
        {
            cout<<result<<endl;
            continue;
        }
        tt = 0;
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                for(ii=i+1; ii<=n; ++ii)
                {
                    for(jj=j+1; jj<=m; ++jj)
                    {
                        if(result <= (ii-i)*(jj-j))
                            break;
                        tt = isMin(i, j, ii, jj);
                        if(k <= tt)
                        {
                            result = min(result, (ii-i)*(jj-j));
                            break;
                        }
                    }
                }
            }
        }
        if(result <= 10000)
            cout<<result<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}




/*
#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][100];
int k;
int result;

bool isMin(int a, int b, int c, int d)
{
    if(c<=a || d<=b)
        return false;
    int t = 0;
    for(int i=a; i<c; ++i)
    {
        for(int j=b; j<d; ++j)
        {
            t = t + arr[i][j];
        }
    }
    if(t >= k)
        return true;
    return false;
}
void matrixMin(int a, int b, int c, int d)
{
    if(isMin(a, b, c, d))
    {
        result = min(result, (c-a)*(d-b));
        matrixMin(a+1, b, c, d);
        matrixMin(a, b+1, c, d);
        matrixMin(a, b, c-1, d);
        matrixMin(a, b, c, d-1);
    }
}

int main()
{
    int n,m;
    int i,j;
    while(cin>>n>>m>>k)
    {
        result = 10001;
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                cin>>arr[i][j];
                if(arr[i][j] >= k)
                {
                    result = 1;
                }
            }
        }
        if(result != 10001)
        {
            cout<<result<<endl;
            continue;
        }
        matrixMin(0, 0, n, m);
        if(result <= 10000)
            cout<<result<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
*/
