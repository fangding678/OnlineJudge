#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct LOG
{
    string str;
    string name;
    string date;
    string time;
    string second;
    bool operator < (const LOG & A) const
    {
        if(second != A.second)
        {
            if(second.size() != A.second.size())
                return second.size() < A.second.size();
            return second < A.second;
        }
        if(date != A.date)
            return date < A.date;
        if(time != A.time)
            return time < A.time;
        return true;
    }
}L[10001];

int main()
{
    int i,cnt=0;
    while(getline(cin, L[cnt].str))
    {
        if(L[cnt].str == "")
            break;
        istringstream is(L[cnt].str);
        is>>L[cnt].name>>L[cnt].date>>L[cnt].time>>L[cnt].second;
        cnt++;
    }
    sort(L, L+cnt);
    for(i=0; i<cnt; ++i)
        cout<<L[i].str<<endl;
    return 0;
}
