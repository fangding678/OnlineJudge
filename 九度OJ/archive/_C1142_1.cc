#include <iostream>

using namespace std;

int main()
{
    int p, e, i, d;
    int cnt,k;
    cnt = 1;
    while(cin>>p>>e>>i>>d)
    {
        if(p==-1 && e == -1 && i == -1 && d == -1)
            break;
        for(k=0;k<d;++k)
        {
            p = (p==0 ? 22 : p-1);
            e = (e==0 ? 27 : e-1);
            i = (i==0 ? 32 : i-1);
        }
        for(k=0;k<21252;++k)
        {
            p = (p==0 ? 22 : p-1);
            e = (e==0 ? 27 : e-1);
            i = (i==0 ? 32 : i-1);
            if(p==0 && e==0 && i==0)
            {
                break;
            }
        }
        cout<<"Case "<<cnt++<<": the next triple peak occurs in "<<k+1<<" days."<<endl;
    }
    return 0;
}
