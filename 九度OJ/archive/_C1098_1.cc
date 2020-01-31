#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    char c;
    int i,len,index;
    int a[26];
    while(getline(cin, str))
    {
        len = str.size();
        for(i=0; i<26; ++i)
            a[i] = 0;
        for(i=0; i<len; ++i)
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                index = str[i] - 'A';
                a[index]++;
            }
        }
        for(i=0; i<26; ++i)
        {
            c = 'A' + i;
            cout<<c<<":"<<a[i]<<endl;
        }
    }
    return 0;
}
