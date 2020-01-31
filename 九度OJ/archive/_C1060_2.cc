#include <iostream>

using namespace std;

int a[11][11];

int calc(int m, int n)
{
    if(m==1 || m==0 || n==1)
        return 1;
    else if(m<0)
        return 0;
    return calc(m-n, n)+calc(m, n-1);
}
void init()
{
    int i,j;
    for(i=1; i<11; ++i)
    {
        for(j=1; j<11; ++j)
        {
            a[i][j] = calc(i, j);
        }
    }
}

int main()
{
    int T,i;
    int m,n;
    init();
    while(cin>>T)
    {
        for(i=0; i<T; ++i)
        {
            cin>>m>>n;
            cout<<a[m][n]<<endl;;
        }
    }
    return 0;
}
