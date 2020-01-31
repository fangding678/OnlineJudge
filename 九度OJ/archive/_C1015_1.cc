#include <iostream>

using namespace std;

int main()
{
    int a,b,k;
    int flag;
    while(cin>>a>>b>>k)
    {
        flag = 1;
        if(a==0 && b==0)
            break;
        while(k--)
        {
            if(a%10 == b%10)
            {
                a /= 10;
                b /= 10;
                if(a==0 || b==0)
                    break;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(!flag)
            cout<<a+b<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
