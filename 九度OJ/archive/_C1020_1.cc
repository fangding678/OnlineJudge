#include <iostream>

using namespace std;

const int N = 500;

int main()
{
    bool a[N],b[N];
    int x,y;
    int rx1,rx2,ry1,ry2;
    int i;
    bool flagx,flagy;
    int num = N/2;
    while(cin>>x>>y)
    {
        if(x==0 && y==0)
            break;
        for(i=0; i<N; ++i)
            a[i] = b[i] = false;
        a[x+num] = true;
        b[y+num] = true;
        while(cin>>x>>y)
        {
            if(x==0 && y==0)
            {
                break;
            }
            a[x+num] = true;
            b[y+num] = true;
        }
        flagx = flagy = true;
        for(i=0; i<N; ++i)
        {
            if(a[i] && flagx)
            {
                flagx = false;
                rx1 = i - num;
            }
            if(b[i] && flagy)
            {
                flagy = false;
                ry1 = i - num;
            }
        }
        flagx = flagy = true;
        for(i=N-1; i>=0; --i)
        {
            if(a[i] && flagx)
            {
                flagx = false;
                rx2 = i - num;
            }
            if(b[i] && flagy)
            {
                flagy = false;
                ry2 = i - num;
            }
        }
        cout<<rx1<<" "<<ry1<<" "<<rx2<<" "<<ry2<<endl;
    }
    return 0;
}
