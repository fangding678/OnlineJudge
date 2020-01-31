#include <iostream>
#include <vector>

using namespace std;

struct bigInt
{
    bool b[502];
    bool flag;
    bigInt()
    {
        flag = false;
        for(int i=0; i<502; ++i)
            b[i] = false;
    }
    bool operator < (const bigInt &t) const
    {
        for(int i=501; i>=0; --i)
        {
            if(b[i] != t.b[i])
            {
                return t.b[i];
            }
        }
        return false;
    }
    bigInt operator + (const bigInt & t)
    {
        bigInt tt;
        tt.flag = true;
        bool v = false;
        //其实这道题目的特殊性，，这个函数的加法可以写简单一些。因为路径中不可能出现两个长度上
        //其中一位是都为true的。。但是我在这里算法还是写全面一点
        for(int i=0; i<502; ++i)
        {
            if(b[i] && t.b[i])
            {
                tt.b[i] = v;
                v = true;
            }
            else if(!b[i] && !t.b[i])
            {
                tt.b[i] = v;
                v = false;
            }
            else
            {
                if(v)
                {
                    tt.b[i] = false;
                    v = true;
                }
                else
                {
                    tt.b[i] = true;
                    v = false;
                }
            }
        }
        return tt;
    }
    friend ostream & operator << (ostream & os, const bigInt & big)
    {
        if(!big.flag)
        {
            os<<-1;
            return os;
        }
        int t = 0;
        for(int i=500; i>=0; --i)
        {
            t *= 2;
            if(big.b[i])
                t++;
            if(t>=100000)
            {
                t %= 100000;
            }
        }
        os<<t;
        return os;
    }
};

struct E
{
    bigInt cost;
    int next;
};
vector<E> edge[100];
bool mark[100];
bigInt Dis[100];
int main()
{
    int n,m;
    int i,j,a,b;
    bigInt c;
    int t;
    int newP;
    while(cin>>n>>m)
    {
        bigInt tt;
        for(i=0; i<100; ++i)
        {
            edge[i].clear();
            mark[i] = false;
            Dis[i] = tt;
        }
        for(i=0; i<m; ++i)
        {
            cin>>a>>b;
            E tmp;
            tmp.next = b;
            tmp.cost.b[i] = true;
            tmp.cost.flag = true;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);
        }
        newP = 0;
        Dis[0].flag = true;
        mark[0] = true;

        for(i=1;i<n;++i)
        {
            for(j=0; j<edge[newP].size(); ++j)
            {
                t = edge[newP][j].next;
                c = edge[newP][j].cost;
                if(mark[t])
                    continue;
                if(!Dis[t].flag || c + Dis[newP] < Dis[t])
                {
                    Dis[t] = c+Dis[newP];
                    Dis[t].flag = true;
                }
            }
            bigInt tmin;
            tmin.b[500] = true;
            tmin.flag = true;
            for(j=0; j<n; ++j)
            {
                if(mark[j])
                    continue;
                if(!Dis[j].flag)
                    continue;
                if(Dis[j] < tmin)
                {
                    tmin = Dis[j];
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        for(i=1; i<n; ++i)
        {
            cout<<Dis[i]<<endl;
        }
    }
    return 0;
}




