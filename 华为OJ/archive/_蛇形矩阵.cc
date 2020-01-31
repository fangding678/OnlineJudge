#include <iostream>
#include <cstring>
#define max 100
using namespace std;


int main()
{
    int n;
    int i,j;
    int t;
    int a[max][max];
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        t=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                a[i-j][j]=t++;
            }
        }
        for(i=0;i<n;i++)
        {
            cout<<a[i][0];
            for(j=1;j<n-i;j++)
                cout<<" "<<a[i][j];
            cout<<endl;
        }
    }
    return 0;
}
