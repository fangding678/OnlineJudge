#include <iostream>

using namespace std;

int jie(int n)
{
    if(n == 0)
        return 1;
    int s = 1;
    while(n)
    {
        s *= n;
        n--;
    }
    return s;
}
int main()
{
    int a, b;
    char c;
    int ans;
    bool flag;
    while(cin>>a)
    {
        cin>>c;
        if(c != '!')
            cin>>b;
        cin.ignore();
        flag = false;
        switch(c)
        {
        case '+':
            ans = a+b;
            break;
        case '-':
            ans = a-b;
            break;
        case '*':
            ans = a*b;
            break;
        case '!':
            ans = jie(a);
            break;
        case '/':
            if(b == 0)
            {
                flag = true;
                break;
            }
            ans = a/b;
            break;
        case '%':
            if(b == 0)
            {
                flag = true;
                break;
            }
            ans = a%b;
            break;
        }
        if(flag)
            cout<<"error"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
