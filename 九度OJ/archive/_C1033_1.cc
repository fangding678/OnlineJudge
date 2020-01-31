#include <iostream>

using namespace std;

int main()
{
    int a[501];
    bool mark[1001];
    int n;
    int i;
    int t;
    while(cin>>n)
    {
        if(n == 0)
            break;
        for(i=1; i<1001; ++i)
        {
            mark[i] = true;
        }
        for(i=0; i<n; ++i)
        {
            cin>>a[i];
            t = a[i];
            while(t!=1)
            {
                if(t & 1)
                    t += (t+1)/2;
                else
                    t >>= 1;
                if(t<1001)
                {
                    if(!mark[t])
                        break;
                    mark[t] = false;
                }
            }
        }
        bool flag = true;
        for(i=n-1; i>=0; --i)
        {
            if(mark[a[i]])
            {
                if(flag)
                {
                    cout<<a[i];
                    flag = false;
                }
                else
                    cout<<" "<<a[i];
            }
        }
        if(!flag)
            cout<<endl;
    }
    return 0;
}




/*
#include <iostream>
#include <algorithm>

using namespace std;

struct A
{
    int cnt;
    int num;
    int level;
    bool flag;
}a[501];

int result[1001];
bool mark[501];

int countLevel(int n)
{
    int le = 0;
    while(n!=1)
    {
        if(n & 1)
            n += (n+1)/2;
        else
            n /= 2;
        le++;
    }
}
void init()
{
    int i;
    for(i=1;i<=1000;++i)
    {
        result[i] = countLevel(i);
    }
}
bool cmp1(const A &a, const A &b)
{
    return a.level > b.level;
}
bool cmp1(const A &a, const A &b)
{
    return a.cnt > b.cnt;
}
int main()
{
    int n;
    int i;
    init();
    while(cin>>n)
    {
        if(n<1 || n>500)
            break;
        for(i=0; i<n; ++i)
        {
            mark[i] = false;
            a[i].cnt = i;
            cin>>a[i].num;
            a[i].level = result[a[i].num];
            a[i].flag = false;
        }
        for(i=0; i<n; ++i)
        {
            for()
        }
    }
    return 0;
}
*/
