#include <iostream>

using namespace std;

int main()
{
    int n;
    int x,y;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>x>>y;
            if(x==y)
            {
                cout<<2*x-x%2<<endl;
            }
            else if(x-2==y)
            {
                cout<<2*x-x%2-2<<endl;
            }
            else
            {
                cout<<"No Number"<<endl;
            }
        }
    }
    return 0;
}
