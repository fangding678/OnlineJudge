#include <iostream>

using namespace std;

int Isrelation(int m)
{
    if(m%7==0)
        return 1;
    while(m)
    {
        if(m%10==7)
            return 1;
        m/=10;
    }
    return 0;
}

int main()
{
    int n,i;
    int count;
    while(cin>>n)
    {
        count=0;
        for(i=7;i<=n;i++)
            if(Isrelation(i))
                count++;
        cout<<count<<endl;
    }
    return 0;
}
