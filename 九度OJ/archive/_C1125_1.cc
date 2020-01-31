#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int E = 100000000;
int main()
{
    string str;
    int a,b,c,d;
    int len,i,t;
    bool mark[10];
    while(cin>>str)
    {
        if(str == "-1")
            break;
        a = b = c = d = 0;
        len = str.size();
        if(len>24)
        {
            for(i=0; i<len-24; ++i)
            {
                a = a*10 + str[i] - '0';
            }
        }
        if(len>16)
        {
            i = max(0, len-24);
            for(; i<len-16; ++i)
            {
                b = b*10 + str[i] - '0';
            }
        }
        if(len>8)
        {
            i = max(0, len-16);
            for(; i<len-8; ++i)
            {
                c = c*10 + str[i] - '0';
            }
        }
        i = max(0, len-8);
        for(; i<len; ++i)
        {
            d = d*10 + str[i] - '0';
        }
        memset(mark, 0, sizeof(mark));
        for(i=9; i>1; --i)
        {
            if(mark[i])
                continue;
            t = a%i;
            t = (b+t*E)%i;
            t = (c+t*E)%i;
            t = (d+t*E)%i;
            if(t == 0)
            {
                mark[i] = true;
                if(i==9 || i==6)
                    mark[3] = true;
                else if(i==8)
                {
                    mark[2] = true;
                    mark[4] = true;
                }
                else if(i==4)
                    mark[2] = true;
            }
        }
        t = 0;
        for(i=2; i<10; ++i)
        {
            if(mark[i])
            {
                if(t==0)
                {
                    cout<<i;
                    t++;
                }
                else
                {
                    cout<<" "<<i;
                    t++;
                }
            }
        }
        if(t == 0)
            cout<<"none";
        cout<<endl;
    }
    return 0;
}
