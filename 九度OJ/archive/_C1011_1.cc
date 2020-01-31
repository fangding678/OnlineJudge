#include <iostream>

using namespace std;

int main()
{
    int a[10000];
    int k;
    int i;
    int result,kmax;
    int kstart,kend;
    int tstart,tend;
    int flag;
    while(cin>>k)
    {
        if(k == 0)
            break;
        for(i=0; i<k; ++i)
            cin>>a[i];
        result = -1;
        kmax = 0;
        kstart = 0;
        kend = k-1;
        tstart = 0;
        tend = k-1;
        flag = 1;
        for(i=0; i<k; ++i)
        {
            if(a[i] > 0)
            {
                if(result < 0)
                {
                    result = a[i];
                    kstart = i;
                    kend = i;
                    if(kmax < result)
                    {
                        tstart = i;
                        tend = i;
                        kmax = result;
                    }
                }
                else if(result == 0)
                {
                    result = a[i];
                    if(kmax < result)
                    {
                        tstart = kend;
                        tend = kend;
                        kmax = result;
                    }
                }
                else
                {
                    result += a[i];
                    kend = i;
                    if(kmax < result)
                    {
                        tstart = kstart;
                        tend = kend;
                        kmax = result;
                    }
                }
            }
            else if(a[i] == 0 && flag == 1)
            {
                flag = 0;
                if(kmax == 0)
                {
                    tstart = tend = i;
                }
            }
            else
            {
                if(result+a[i] >= 0)
                    result += a[i];
                else
                    result = -1;
            }
        }
        cout<<kmax<<" "<<a[tstart]<<" "<<a[tend]<<endl;
    }
    return 0;
}
