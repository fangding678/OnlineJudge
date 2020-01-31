#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s,str;
    int i;
    int len1;
    int a[5];
    while(getline(cin,s))
    {
        if(s == "#")
            break;
        getline(cin, str);
        len1 = s.size();
        for(i=0; i<len1; ++i)
            a[i] = 0;
        for(i=0; i<len1; ++i)
        {
            a[i] = count(str.begin(), str.end(), s[i]);
        }
        for(i=0; i<len1; ++i)
            cout<<s[i]<<" "<<a[i]<<endl;
    }
    return 0;
}

/*此代码可以提交，但是我们需要练习使用STL
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s,str;
    int i,j;
    int len1,len2;
    int a[5];
    while(getline(cin,s))
    {
        if(s == "#")
            break;
        getline(cin, str);
        len1 = s.size();
        len2 = str.size();
        for(i=0; i<len1; ++i)
            a[i] = 0;
        for(i=0; i<len2; ++i)
        {
            for(j=0; j<len1; ++j)
            {
                if(str[i] == s[j])
                    a[j]++;
            }
        }
        for(i=0; i<len1; ++i)
            cout<<s[i]<<" "<<a[i]<<endl;
    }
    return 0;
}
*/
