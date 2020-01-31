#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct C
{
    int data;
    vector<int> cost;
};

bool Comp(const int &a, const int &b)
{
	return a>b;
}

int main()
{
    int Q,n,i,j,k;
    int a,b;
    C c[21];
    double t;
    int len;
    int result,tt;
    vector<int> d;
    vector<int> e;
    vector<int> f;
    cin>>Q;
    while(Q--)
    {
        result = 0;
        d.clear();
        e.clear();
        f.clear();
        cin>>n;
        for(i=0; i<21; ++i)
        {
            c[i].data = 0;
            c[i].cost.clear();
        }
        for(i=0; i<n; ++i)
        {
            cin>>t>>b;
            a = (int)(2*t);
            c[a].cost.push_back(b);
            c[a].data++;
        }

        //一次性买两包
        for(i=1; i<5; ++i)
        {
            if(c[i].data!=0 && c[10-i].data!=0)
            {
                sort(c[i].cost.begin(), c[i].cost.end(), Comp);
                sort(c[10-i].cost.begin(), c[10-i].cost.end(), Comp);
                len = c[i].data<c[10-i].data ? c[i].data : c[10-i].data;
                for(j=0; j<len; ++j)
                {
                    d.push_back(c[i].cost[j]+c[10-i].cost[j]);
                }
            }
        }
        if(c[5].data>1)
        {
            sort(c[5].cost.begin(), c[5].cost.end(), Comp);
            d.push_back(c[5].cost[0]+c[5].cost[1]);
        }
        for(i=1; i<10; ++i)
        {
            if(c[i].data!=0 && c[20-i].data!=0)
            {
                sort(c[i].cost.begin(), c[i].cost.end(), Comp);
                sort(c[20-i].cost.begin(), c[20-i].cost.end(), Comp);
                len = c[i].data<c[20-i].data ? c[i].data : c[20-i].data;
                for(j=0; j<len; ++j)
                {
                    d.push_back(c[i].cost[j]+c[20-i].cost[j]);
                }
            }
        }
        for(i=11; i<15; ++i)
        {
            if(c[i].data!=0 && c[30-i].data!=0)
            {
                sort(c[i].cost.begin(), c[i].cost.end(), Comp);
                sort(c[30-i].cost.begin(), c[30-i].cost.end(), Comp);
                len = c[i].data<c[30-i].data ? c[i].data : c[30-i].data;
                for(j=0; j<len; ++j)
                {
                    d.push_back(c[i].cost[j]+c[30-i].cost[j]);
                }
            }
        }
        if(c[15].data>1)
        {
            sort(c[15].cost.begin(), c[15].cost.end(), Comp);
            d.push_back(c[15].cost[0]+c[15].cost[1]);
        }

        //一次性买一包
        if(c[10].data != 0)
        {
            for(j=0; j<c[10].data; ++j)
                e.push_back(c[10].cost[j]);
        }
        if(c[20].data != 0)
        {
            for(j=0; j<c[20].data; ++j)
                e.push_back(c[20].cost[j]);
        }
        if(!e.empty())
            sort(e.begin(), e.end(), Comp);
        if(!d.empty())
            sort(d.begin(), d.end(), Comp);

        //判断一次性买一包和两包的情况.e表示一包，d表示两包
        if(d.empty() && e.empty())
            result = 0;
        else if(d.empty())
        {
            len = e.size()>3 ? 3 : e.size();
            for(j=0; j<len; ++j)
                result += e[j];
        }
        else if(e.empty())
        {
            result = d[0];
        }
        else
        {
            len = e.size()>3 ? 3 : e.size();
            tt = 0;
            for(i=0; i<len; ++i)
                tt += e[i];
            result = d[0] + e[0];
            result = tt>result ? tt : result;
        }

        //一次性买三包零食的时候
        for(i=1; i<21; ++i)
        {
            if(c[i].data == 0)
                continue;
            for(j=i+1; j<21; ++j)
            {
                if(c[j].data == 0)
                    continue;
                for(k=j+1; k<21; ++k)
                {
                    if(c[k].data == 0)
                        continue;
                    if((i+j+k)%10 == 0)
                        f.push_back(c[i].cost[0]+c[j].cost[0]+c[k].cost[0]);
                }
            }
        }
        if(!f.empty())
        {
            sort(f.begin(), f.end(), Comp);
            result = f[0]>result ? f[0] : result;
        }

        cout<<result<<endl;
    }
    return 0;
}



/*提交错误。。但是有60分
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct C
{
    int data;
    vector<int> cost;
};

bool Comp(const int &a, const int &b)
{
	return a>b;
}

int main()
{
    int Q,n,i,j,k;
    int a,b;
    C c[21];
    double t;
    int len;
    int result,tt;
    vector<int> d;
    vector<int> e;
    vector<int> f;
    while(cin>>Q)
    {
        while(Q--)
        {
            result = 0;
            d.clear();
            e.clear();
            f.clear();
            cin>>n;
            for(i=0; i<21; ++i)
            {
                c[i].data = 0;
                c[i].cost.clear();
            }
            for(i=0; i<n; ++i)
            {
                cin>>t>>b;
                a = (int)(2*t);
                c[a].cost.push_back(b);
                c[a].data++;
            }

            //一次性买两包
            for(i=1; i<5; ++i)
            {
                if(c[i].data!=0 && c[10-i].data!=0)
                {
                    sort(c[i].cost.begin(), c[i].cost.end(), Comp);
                    sort(c[10-i].cost.begin(), c[10-i].cost.end(), Comp);
                    len = c[i].data<c[10-i].data ? c[i].data : c[10-i].data;
                    for(j=0; j<len; ++j)
                    {
                        d.push_back(c[i].cost[j]+c[10-i].cost[j]);
                    }
                }
            }
            if(c[5].data>1)
            {
                sort(c[5].cost.begin(), c[5].cost.end(), Comp);
                d.push_back(c[5].cost[0]+c[5].cost[1]);
            }
            for(i=1; i<10; ++i)
            {
                if(c[i].data!=0 && c[20-i].data!=0)
                {
                    sort(c[i].cost.begin(), c[i].cost.end(), Comp);
                    sort(c[20-i].cost.begin(), c[20-i].cost.end(), Comp);
                    len = c[i].data<c[20-i].data ? c[i].data : c[20-i].data;
                    for(j=0; j<len; ++j)
                    {
                        d.push_back(c[i].cost[j]+c[20-i].cost[j]);
                    }
                }
            }
            for(i=10; i<15; ++i)
            {
                if(c[i].data!=0 && c[30-i].data!=0)
                {
                    sort(c[i].cost.begin(), c[i].cost.end(), Comp);
                    sort(c[30-i].cost.begin(), c[30-i].cost.end(), Comp);
                    len = c[i].data<c[30-i].data ? c[i].data : c[30-i].data;
                    for(j=0; j<len; ++j)
                    {
                        d.push_back(c[i].cost[j]+c[30-i].cost[j]);
                    }
                }
            }
            if(c[15].data>1)
            {
                sort(c[15].cost.begin(), c[15].cost.end(), Comp);
                d.push_back(c[15].cost[0]+c[15].cost[1]);
            }

            //一次性买一包
            if(c[10].data != 0)
            {
                sort(c[10].cost.begin(), c[10].cost.end(), Comp);
                for(j=0; j<c[10].data; ++j)
                    e.push_back(c[10].cost[j]);
            }
            if(c[20].data != 0)
            {
                sort(c[20].cost.begin(), c[20].cost.end(), Comp);
                for(j=0; j<c[20].data; ++j)
                    e.push_back(c[20].cost[j]);
            }

            //判断一次性买一包和两包的情况
            if(d.empty() && e.empty())
                result = 0;
            else if(d.empty())
            {
                sort(e.begin(), e.end(), Comp);
                len = e.size()>3 ? 3 : e.size();
                for(j=0; j<len; ++j)
                    result += e[j];
            }
            else if(e.empty())
            {
                sort(d.begin(), d.end(), Comp);
                result = d[0];
            }
            else
            {
                sort(d.begin(), d.end(), Comp);
                sort(e.begin(), e.end(), Comp);
                len = e.size()>3 ? 3 : e.size();
                tt = 0;
                for(i=0; i<len; ++i)
                    tt += e[i];
                result = d[0] + e[0];
                result = tt>result ? tt : result;
            }

            //一次性买三包零食的时候
            for(i=1; i<21; ++i)
            {
                if(c[i].data == 0)
                    continue;
                for(j=i+1; j<21; ++j)
                {
                    if(c[j].data == 0)
                        continue;
                    for(k=j+1; k<21; ++k)
                    {
                        if(c[k].data == 0)
                            continue;
                        if((i+j+k)%10 == 0)
                            f.push_back(c[i].cost[0]+c[j].cost[0]+c[k].cost[0]);
                    }
                }
            }
            if(!f.empty())
            {
                sort(f.begin(), f.end(), Comp);
                result = f[0]>result ? f[0] : result;
            }

            cout<<result<<endl;
        }
    }
    return 0;
}
*/
