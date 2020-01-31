#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    string str;
    set<string> s;
    set<string>::iterator it;
    int i,len;
    while(getline(cin,str))
    {
        s.clear();
        len = str.size();
        for(i=0; i<len; ++i)
        {
            s.insert(str.substr(i,len));
        }
        for(it=s.begin(); it!=s.end(); ++it)
            cout<<*it<<endl;
    }
    return 0;
}
