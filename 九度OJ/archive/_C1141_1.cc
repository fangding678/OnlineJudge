#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double sum,avg,t;
    while(cin>>t)
    {
        sum = t;
        for(int i=1; i<12; ++i)
        {
            cin>>t;
            sum += t;
        }
        avg = sum/12.0;
        cout<<"$"<<fixed<<setprecision(2)<<avg<<endl;
    }
    return 0;
}
