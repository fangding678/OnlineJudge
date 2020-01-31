#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double ans,sum,t;
    while(cin>>t)
    {
        sum = t;
        for(int i=1; i<12; ++i)
        {
            cin>>t;
            sum += t;
        }
        cout<<fixed<<setprecision(2)<<"$"<<sum/12<<endl;
    }
    return 0;
}
