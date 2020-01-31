#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string str;
    int i,ans,len;
    while(cin>>str)
    {
        if(str == "0")
            break;
        len = str.size();
        ans = 0;
        for(i=0; i<len; ++i)
        {
            if(str[i] == '1')
            {
                ans += pow(2, len-i) - 1;
            }
            else if(str[i] == '2')
            {
                ans += pow(2, len-i+1) - 2;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
