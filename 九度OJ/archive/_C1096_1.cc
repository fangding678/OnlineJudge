#include <iostream>

using namespace std;
int a[5001][13][32];
int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
struct T
{
    int year;
    int month;
    int day;
    bool operator < (const T & t)const
    {
        if(year != t.year)
            return year < t.year;
        if(month != t.month)
            return month < t.month;
        if(day != t.day)
            return day < t.day;
    }
    int operator - (const T & t)const
    {
        return a[year][month][day] - a[t.year][t.month][t.day];
    }
};
void init()
{
    int i,j,k;
    int f;
    int cnt = 1;
    for(i=1; i<5001; ++i)
    {
        if((i%4==0 && i%100!=0) || i%400==0)
            f = 1;
        else
            f = 0;
        for(j=1; j<13; ++j)
        {
            for(k=1; k<=m[j]; ++k)
            {
                a[i][j][k] = cnt++;
            }
            if(j==2 && f==1)
                a[i][j][m[2]+1] = cnt++;
        }
    }
}
T Tran(int n)
{
    T t;
    t.year = n/10000;
    t.month = (n%10000)/100;
    t.day = n%100;
    return t;
}
int main()
{
    int n,m;
    T t1,t2;
    init();
    int ans;
    while(cin>>n>>m)
    {
        t1 = Tran(n);
        t2 = Tran(m);
        ans = t1-t2;
        if(ans < 0)
            ans = -1*ans;
        ans++;
        cout<<ans<<endl;
    }
    return 0;
}
