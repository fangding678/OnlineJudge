#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int mark[101];
    int a[10];
    int i;
    bool flag;
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9])
    {
        memset(mark, 0, 101*sizeof(mark[0]));
        for(i=0; i<10; ++i)
        {
            mark[a[i]]++;
        }
        flag = true;
        for(i=99; i>0; i-=2)
        {
            while(mark[i])
            {
                if(flag)
                {
                    flag = false;
                    cout<<i;
                    mark[i]--;
                    continue;
                }
                cout<<" "<<i;
                mark[i]--;
            }
        }
        for(i=0; i<101; i+=2)
        {
            while(mark[i])
            {
                if(flag)
                {
                    flag = false;
                    cout<<i;
                    mark[i]--;
                    continue;
                }
                cout<<" "<<i;
                mark[i]--;
            }
        }
        cout<<endl;
    }
    return 0;
}
