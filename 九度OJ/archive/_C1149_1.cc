#include <iostream>
#include <map>

using namespace std;

int main()
{
    string str,t;
    map<string, int>m;
    int i,j,len;
    while(cin>>str)
    {
        m.clear();
        len = str.size();
        for(i=0; i<len; ++i)
        {
            for(j=1; j<=len-i; ++j)
            {
                t = str.substr(i,j);
                if(m[t] >= 1)
                    m[t] += 1;
                else
                    m[t] = 1;
            }
        }
        for(map<string,int>::iterator it=m.begin();it!=m.end();++it)
        {
            if(it->second > 1)
                cout<<it->first<<" "<<it->second<<endl;
        }
    }
    return 0;
}
