#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<char, char> m;
    string s[4] = {"ZXCVBNM,./", "ASDFGHJKL;'", "QWERTYUIOP[]\\", "1234567890-="};
    string str;
    int i,j;
    for(i=0; i<4; ++i)
    {
        for(j=0; j<s[i].size()-1; ++j)
        {
            m[s[i][j+1]] = s[i][j];
        }
    }
    m[' '] = ' ';
    m['`'] = '1';
    while(getline(cin,str))
    {
        for(i=0; i<str.size(); ++i)
        {
            cout<<m[str[i]];
        }
        cout<<endl;
    }
    return 0;
}
