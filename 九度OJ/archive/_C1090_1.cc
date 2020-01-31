#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(string a, string b)
{
    int len = a.size() > b.size() ? b.size() : a.size();
    for(int i=0; i<len; ++i)
    {
        if(a[i] != b[i])
        {
            if(a[i] != '\\' && b[i] != '\\')
                return a[i] < b[i];
            else if(a[i] == '\\')
                return true;
            else if(b[i] == '\\')
                return false;
        }
    }
    return a.size() < b.size();
}

int main()
{
    int n;
    int i,j,index;
    string str;
    vector<string> vstr;
    while(cin>>n)
    {
        if(n == 0)
            break;
        vstr.clear();
        for(i=0; i<n; ++i)
        {
            cin>>str;
            if(str[str.size()-1] == '\\')
                str.erase(str.size()-1, str.size());
            if(find(vstr.begin(), vstr.end(), str) == vstr.end())
                vstr.push_back(str);
            while(str.find('\\') != string::npos)
            {
                str.erase(str.find_last_of('\\', str.size()));
                if(find(vstr.begin(), vstr.end(), str) == vstr.end())
                    vstr.push_back(str);
            }
        }
        sort(vstr.begin(), vstr.end(), comp);
        for(unsigned int i=0; i<vstr.size(); ++i)
        {
            if(vstr[i].find('\\') == string::npos)
                cout<<vstr[i]<<endl;
            else
            {
                index = vstr[i].find_last_of('\\');
                for(j=0; j<=index; ++j)
                    cout<<" ";
                cout<<vstr[i].substr(index+1, vstr[i].size())<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
