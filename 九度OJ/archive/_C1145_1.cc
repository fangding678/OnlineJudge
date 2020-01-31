#include <iostream>

using namespace std;

bool hege(int *a, int n)
{
    int t = a[0];
    for(int i=1; i<n; ++i)
    {
        if(t!=a[i])
            return false;
    }
    return true;
}
int main()
{
    int n,i;
    int *a,*b;
    int cnt;
    while(cin>>n)
    {
        if(n==0)
            break;
        a = new int[n];
        b = new int[n];
        for(i=0; i<n; ++i)
        {
            cin>>a[i];
        }
        cnt = 0;
        while(1)
        {
            for(i=1; i<n; ++i)
            {
                b[i] = (a[i-1]+a[i])/2;
            }
            b[0] = (a[0]+a[n-1])/2;
            for(i=0; i<n; ++i)
            {
                a[i] = b[i];
                if(a[i]%2 == 1)
                    a[i]++;
            }
            cnt++;
            if(hege(a, n))
            {
                break;
            }
        }
        cout<<cnt<<" "<<a[0]<<endl;
        delete []a;
        delete []b;
    }
    return 0;
}
