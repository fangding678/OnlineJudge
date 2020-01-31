#include <iostream>
#include <string>

using namespace std;
int cnt[3001][13][32];
string week[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
string month[12] = {"January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};
int num[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
void init()
{
    int c=1;
    int i,j,k;
    int flag;
    for(i=1000; i<3001; ++i)
    {
        if((i%4==0 && i%100!=0) || (i%400==0))
            flag = 1;
        else
            flag = 0;
        for(j=1; j<13; ++j)
        {
            for(k=1; k<=num[j]; ++k)
            {
                cnt[i][j][k] = c++;
            }
            if(flag==1 && j==2)
            {
                cnt[i][j][k] = c++;
            }
        }
    }
}
struct Date
{
    int day;
    int month;
    int year;
    Date(int d=0, int m=0, int y=0)
    {
        day = d;
        month = m;
        year = y;
    }
    int operator - (const Date & date) const
    {
        return cnt[year][month][day] - cnt[date.year][date.month][date.day];
    }
};

int main()
{
    int d,m,y;
    int i;
    string result;
    init();
    Date today(12,12,2015);
    Date da;
    int dis;
    while(cin>>d>>result>>y)
    {
        for(i=0; i<12; ++i)
        {
            if(month[i] == result)
            {
                m = i+1;
                break;
            }
        }
        da.day = d;
        da.month = m;
        da.year = y;
        dis = da - today;
        dis = (dis%7 + 7)%7;
        cout<<week[dis]<<endl;
    }
    return 0;
}
