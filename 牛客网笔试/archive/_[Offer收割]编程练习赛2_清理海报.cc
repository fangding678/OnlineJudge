#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P
{
    int x,y;
    P(int xx=0, int yy=0)
    {
        x = xx;
        y = yy;
    }
};

bool isInArea(P &p1, P &p2, P &p)
{
    if((p.x<p2.x && p.y<p2.y) && (p.x>p1.x && p.y>p2.y))
        return true;
    return false;
}

struct Seal
{
    P ps,pe;
    bool isOut(Seal &s)
    {
        P p(ps.x-s.ps.x, ps.y-s.ps.y);
        bool b = isInArea(p, pe, s.ps);
        if(b)
            return false;
        return true;
    }
};

struct Tag
{
    int index;
    int num;
    Tag(int t=0, int n=0)
    {
        index = t;
        num = n;
    }
    bool operator < (const Tag &t) const
    {
        return ((num>t.num)||(num==t.num && index < t.index));
    }
};

int main()
{
    int w,h,n,i,j,k;
    int len1,len2;
    Seal s[1001],ss;
    vector<vector<Seal> > tp;
    bool flag;
    int cnt;
    while(cin>>w>>h>>n)
    {
        Tag tag[1001];
        vector<Seal> tt;
        tp.clear();
        tt.clear();
        cin>>s[1].ps.x>>s[1].ps.y>>s[1].pe.x>>s[1].pe.y;
        tag[0].index = 1;
        tag[0].num = 1;
        cnt = 1;
        tt.push_back(s[1]);
        tp.push_back(tt);
        for(i=2; i<=n; ++i)
        {
            cin>>s[i].ps.x>>s[i].ps.y>>s[i].pe.x>>s[i].pe.y;
            flag = true;
            len1 = tp.size();
            for(j=0; j<len1; ++j)
            {
                len2 = tp[j].size();
                for(k=0; k<len2; ++k)
                {
                    if(!(tp[j][k].isOut(s[i])))
                    {
                        tp[j].push_back(s[i]);
                        tag[j].num++;
                        flag = false;
                    }
                }
            }
            if(flag)
            {
                vector<Seal> ts;
                ts.push_back(s[i]);
                tp.push_back(ts);
                tag[cnt].index = i;
                tag[cnt].num = 1;
                cnt++;
            }
        }
        sort(tag, tag+cnt);
        cout<<tag[0].num<<" "<<tag[0].index<<endl;
    }
    return 0;
}
