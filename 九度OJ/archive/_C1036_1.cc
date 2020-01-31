#include <iostream>

using namespace std;

int main()
{
    int num;
    int a,b,c;
    int sum,t,price;
    int i,j;
    int flag;
    while(cin>>num)
    {
        cin>>a>>b>>c;
        sum = a*1000 + b*100 + c*10;
        for(i=9; i>0; --i)
        {
            flag = 0;
            t = sum + i*10000;
            for(j=9; j>=0; --j)
            {
                if((t+j)%num == 0)
                {
                    flag = 1;
                    price = (t+j)/num;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag == 0)
            cout<<0<<endl;
        else
            cout<<i<<" "<<j<<" "<<price<<endl;
    }
    return 0;
}
