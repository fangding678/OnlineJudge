#include <iostream>
#include <string>

using namespace std;

int main()
{
    string T,P;
    size_t index;
    int ans;
    while(cin>>T>>P)
    {
        ans = 0;
        index = T.find(P);
        while(index != string::npos)
        {
            ans++;
            index = T.find(P, index+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
