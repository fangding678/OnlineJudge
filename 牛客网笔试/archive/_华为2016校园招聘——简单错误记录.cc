#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
    int rak;
    int cnt;
    info(int r, int c)
    {
        rak = r;
        cnt = c;
    }
    bool operator < (const info &a) const
    {
        if(cnt == a.cnt)
            return rak < a.rak;
        return cnt > a.cnt;
    }
};

bool cmp(const pair<string, info> &a, const pair<string, info> &b)
{
    return a.second < b.second;
}

int main()
{
    string str,s;
    unordered_map<string,info> record;
    unordered_map<string,info>::iterator itfind;
    vector<pair<string,info> > v;
    vector<pair<string,info> >::iterator itv;
    int i = 0,pos;
    while(getline(cin, str))
    {
        ++i;
        if(str.length() == 0)
            break;
        pos = str.rfind("\\");
        s = str.substr(pos+1);
        itfind = record.find(s);
        if(itfind == record.end())
        {
            info tmp(i, 1);
            record.insert(pair<string, info>(s, tmp));
        }
        else
        {
            info tmp(itfind->second.rak, itfind->second.cnt+1);
            record.erase(s);
            record.insert(pair<string, info>(s, tmp));
        }
    }
    for(itfind = record.begin(); itfind != record.end(); ++itfind)
    {
        v.push_back(make_pair(itfind->first, itfind->second));
    }
    sort(v.begin(), v.end(), cmp);
    int j = 0;
    for(itv=v.begin(); itv!=v.end()&&j<8; j++,++itv)
    {
        s = (*itv).first;
        if(s.find(" ") <=16 )
            cout<<s<<" "<<(*itv).second.cnt<<endl;
        else
        {
            cout<<s.substr(s.find(" ")-16)<<" "<<(*itv).second.cnt<<endl;
        }
    }
    return 0;
}
