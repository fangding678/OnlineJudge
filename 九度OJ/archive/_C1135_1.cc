#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(string s1, string s2)
{
    return s1.size() < s2.size();
}
int main()
{
    vector<string> vstr;
    string str;
    int i,n;
    vector<string>::iterator it;
    while(cin>>n)
    {
        vstr.clear();
        cin.ignore();
        for(i=0; i<n; ++i)
        {
            getline(cin, str);
            if(str == "stop")
                break;
            vstr.push_back(str);
        }
        sort(vstr.begin(), vstr.end(), cmp);
        for(it=vstr.begin(); it!=vstr.end(); ++it)
            cout<<*it<<endl;
    }
    return 0;
}
