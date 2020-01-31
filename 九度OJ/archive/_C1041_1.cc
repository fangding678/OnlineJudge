#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n,t;
    set<int> s;
    set<int>::iterator it;
    while(cin>>n)
    {
        s.clear();
        while(n-->0)
        {
            cin>>t;
            s.insert(t);
        }
        t=1;
        for(it=s.begin(); it!=s.end(); ++it)
        {
            if(t)
            {
                cout<<*it;
                t = 0;
            }
            else
                cout<<" "<<*it;
        }
        cout<<endl;
    }
    return 0;
}
