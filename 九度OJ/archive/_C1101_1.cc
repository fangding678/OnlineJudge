#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool pri(char a, char b)
{
    if((a=='*' || a=='/')&&(b=='+' || b=='-'))
        return true;
    return false;
}
int cal(double a, double b, char c)
{
    double d;
    switch(c)
    {
    case '+':
        d = a + b;
        break;
    case '-':
        d = a - b;
        break;
    case '*':
        d = a * b;
        break;
    case '/':
        d = a / b;
        break;
    }
    return d;
}
int main()
{
    string str;
    double data[102];
    char c[102],ch,cc;
    stack<double> da;
    stack<char> op;
    int i,len;
    double x,y;
    double result;
    int cnt;
    while(cin>>str)
    {
        while(!da.empty())
            da.pop();
        while(!op.empty())
            op.pop();
        len = str.size();
        cnt = 0;
        for(i=0; i<102; ++i)
            data[i] = 0;
        for(i=0; i<len; ++i)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                data[cnt] = data[cnt]*10 + str[i] - '0';
            }
            else
            {
                c[cnt] = str[i];
                cnt ++;
            }
        }
        if(cnt == 0)
        {
            cout<<str<<endl;
            continue;
        }
        c[cnt] = 0;
        da.push(data[0]);
        op.push(c[0]);
        da.push(data[1]);
        for(i=1; i<cnt; ++i)
        {
            if(!op.empty())
            {
                ch = op.top();
                if(pri(c[i], ch))
                {
                    da.push(data[i+1]);
                    op.push(c[i]);
                }
                else
                {
                    x = da.top();
                    da.pop();
                    y = da.top();
                    da.pop();
                    cc = op.top();
                    op.pop();
                    x = cal(y, x, cc);
                    da.push(x);
                    i--;
                }
            }
            else
            {
                op.push(c[i]);
                da.push(data[i+1]);
            }
        }
        while(!op.empty())
        {
            x = da.top();
            da.pop();
            y = da.top();
            da.pop();
            cc = op.top();
            op.pop();
            result = cal(y, x, cc);
            da.push(result);
        }
        cout<<result<<endl;
    }
    return 0;
}
