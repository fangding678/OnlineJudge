#include <iostream>
#include <string>
#include <map>
#include <cstdio>

using namespace std;

map<string, string> dictionary;
int main()
{
    string strKey,strValue,str;
    string ans;
    int n;
    while(getline(cin, str))
    {
        if(str == "@END@")
            break;
        size_t pos = str.find(']');
        strKey = str.substr(0, pos+1);
        strValue = str.substr(pos+2);
        //cout<<strKey<<endl<<strValue<<endl;
        dictionary.insert(make_pair(strKey, strValue));
        dictionary.insert(make_pair(strValue, strKey));
    }
    cin>>n;
    getchar();
    while(n--)
    {
        getline(cin, str);
        if(dictionary.find(str) == dictionary.end())
            ans = "what?";
        else
            ans = dictionary[str];
        if(ans[0] == '[')
            ans = ans.substr(1,ans.size()-2);
        cout<<ans<<endl;
    }
    return 0;
}
