#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct T
{
    int hour,minute,second;
    bool operator < (const T &A) const
    {
        return (hour<A.hour || (hour == A.hour && (minute < A.minute || (minute == A.minute && second < A.second))));
    }
};

struct P
{
    T tstart,tend;
    string name;
}p[10001];

T ToTime(string s)
{
    T tmp;
    tmp.hour = (s[0]-'0')*10 + (s[1]-'0');
    tmp.minute = (s[3]-'0')*10 + (s[4]-'0');
    tmp.second = (s[6]-'0')*10 + (s[7]-'0');
    return tmp;
}
/*
bool isStart(const P &p1, const P &p2)
{
    return p1.tstart < p2.tstart;
}
bool isEnd(const P &p1, const P &p2)
{
    return !(p1.tend < p2.tend);
}
*/
int main()
{
    int n,m;
    int i;
    string kstart,kend;
    P temp1,temp2;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>m;
            for(i=0; i<m; ++i)
            {
                cin>>p[i].name>>kstart>>kend;
                p[i].tstart = ToTime(kstart);
                p[i].tend = ToTime(kend);
                if(i == 0)
                {
                    /*temp1.name = temp2.name = p[i].name;
                    temp1.tend = temp2.tend = p[i].tend;
                    temp1.tstart = temp2.tstart = p[i].tstart;*/
                    temp1 = p[i];
                    temp2 = p[i];
                }
                if(p[i].tstart < temp1.tstart)
                    temp1 = p[i];
                if(temp2.tend < p[i].tend)
                    temp2 = p[i];
            }
            cout <<temp1.name<<" "<<temp2.name<< endl;
        }
    }
    return 0;
}
