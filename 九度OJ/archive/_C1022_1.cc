#include <iostream>
#include <string>

using namespace std;
const int N = 101;
struct Time
{
    int hour;
    int minute;
    int operator - (const Time &A) const
    {
        return (hour - A.hour)*60 + minute - A.minute;
    }
};
struct People
{
    int flag;
    int name;
    Time tstart,tend;
}p[N];

int main()
{
    int num;
    char c;
    int n,t;
    string s1;
    int h,m;
    int i;
    while(cin>>num)
    {
        if(num == -1)
            break;
        for(i=0; i<N; ++i)
        {
            p[i].flag = 0;
        }
        n = 0;
        t = 0;
        cin>>s1>>h>>c>>m;
        if(s1 == "S")
        {
            p[num].flag = 1;
            p[num].tstart.hour = h;
            p[num].tstart.minute = m;
        }
        if(s1 == "E" && p[num].flag == 1)
        {
            p[num].flag = 2;
            p[num].tend.hour = h;
            p[num].tend.minute = m;
        }
        while(num != 0)
        {

            if(s1 == "S")
            {
                p[num].flag = 1;
                p[num].tstart.hour = h;
                p[num].tstart.minute = m;
            }
            if(s1 == "E" && p[num].flag == 1)
            {
                p[num].flag = 2;
                p[num].tend.hour = h;
                p[num].tend.minute = m;
            }
            cin>>num>>s1>>h>>c>>m;
        }
        for(i=0; i<N; ++i)
        {
            if(p[i].flag == 2)
            {
                n++;
                t += p[i].tend - p[i].tstart;
            }
        }
        if(n != 0)
            cout<<n<<" "<<(t+n/2)/n<<endl; //很好的写法，解决除法的四舍五入
        else
            cout<<0<<" "<<0<<endl;
    }
    return 0;
}
