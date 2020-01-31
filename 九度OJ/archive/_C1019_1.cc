#include <iostream>
#include <stack>
#include <string>
#include <cctype>
//#include <iomanip>
#include <stdio.h>

using namespace std;

bool Pri(char a, char b)
{
    if((a=='*'||a=='/')&&(b=='+'||b=='-'))
        return true;
    return false;
}
double Cal(double x, double y, int c)
{
    double re;
    if(c == '+')
        re = x + y;
    else if(c == '-')
        re = x - y;
    else if(c == '*')
        re = x * y;
    else
        re = x / y;
    return re;
}
int main()
{
    string str;
    int data[102];
    char c[102];
    char ch;
    stack<char> op;
    stack<double> da;
    int i,t,k;
    int len;
    double x,y,z;
    while(getline(cin,str))
    {
        if(str == "0")
            break;
        len = str.size();
        for(i=0; i<101; ++i)
        {
            data[i] = 0;
            c[i] = 0;
        }
        k=0;
        for(i=0; i<len; ++i)
        {
            if(isdigit(str[i]))
            {
                t = str[i] - '0';
                data[k] = data[k]*10 + t;
            }
            else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
            {
                c[k] = str[i];
                k++;
            }
        }
        if(k == 0)
        {
            cout<<str<<endl;
            continue;
        }
        da.push(data[0]);
        op.push(c[0]);
        da.push(data[1]);
        for(i=1; i<k; ++i)
        {
            if(!op.empty())
            {
                ch = op.top();
                if(Pri(c[i], ch))
                {
                    op.push(c[i]);
                    da.push(data[i+1]);
                }
                else
                {
                    y = da.top();
                    da.pop();
                    x = da.top();
                    da.pop();
                    op.pop();
                    z = Cal(x, y, ch);
                    da.push(z);
                    i--;
                }
            }
            else
            {
                op.push(c[i]);
                da.push(data[i+1]);
            }
        }
        z = da.top();
        da.pop();
        while(!op.empty())
        {
            x = da.top();
            da.pop();
            y = z;
            ch = op.top();
            op.pop();
            z = Cal(x, y, ch);
        }
        printf("%0.2lf\n",z);
        //cout<<setioflags(io::fixed)<< setprecision(2)<<z<<endl;
    }
    return 0;
}
