#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str[10000];
    int n,i;
    while(cin>>n)
    {
        for(i=0; i<n; ++i)
            cin>>str[i];
        cout<<str[n-1];
        for(i=n-2; i>=0; --i)
        {
            cout<<" "<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
