#include <iostream>

using namespace std;

int main()
{
    int n,k,i;
    double sum,price,rate;
    while(cin>>n>>k)
    {
        sum = n;
        price = 200;
        rate = 1+double(k)/100;
        for(i=1; i<=20; ++i)
        {
            if(sum >= price)
                break;
            sum += n;
            price *= rate;
        }
        if(i>20)
            cout<<"Impossible"<<endl;
        else
            cout<<i<<endl;
    }
    return 0;
}
