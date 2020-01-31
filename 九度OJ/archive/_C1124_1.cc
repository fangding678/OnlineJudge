#include <iostream>
#include <string>

using namespace std;

int main()
{
    int len,n,t;
    string str;
    while(cin>>str)
    {
        if(str=="0")
            break;
        len = str.size();
        n = 0;
        for(int i=0; i<len; ++i)
        {
            n += str[i] - '0';
        }
        while(n>9)
        {
            t = 0;
            while(n)
            {
                t += n%10;
                n /= 10;
            }
            n = t;
        }
        cout<<n<<endl;
    }
    return 0;
}
