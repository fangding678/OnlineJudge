#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    string str,s1,s2;
    int index,i,j;
    int a,b,c;
    int temp,k;
    int len1,len2;
    bool flag;
    while(cin>>str)
    {
        index = str.find('=');
        s1 = str.substr(0, index);
        s2 = str.substr(index+1, str.size());
        len1 = s1.size();
        len2 = s2.size();
        a = b = c = 0;
        //查找x^2
        i = 0;
        i = s1.find("x^2", i);
        while(i != string::npos)
        {
            temp = 0;
            k = 0;
            for(j=i-1; j>=0; j--)
            {
                if(s1[j]<'0' || s1[j]>'9')
                    break;
                temp += (s1[j] - '0') * pow(10,k);
                k++;
            }
            if(temp == 0)
                temp = 1;
            if(j>=0 && s1[j]=='-')
            {
                a -= temp;
            }
            else
            {
                a += temp;
            }
            i = s1.find("x^2", i+1);
        }
        i = 0;
        i = s2.find("x^2", i);
        while(i != string::npos)
        {
            temp = 0;
            k = 0;
            for(j=i-1; j>=0; j--)
            {
                if(s2[j]<'0' || s2[j]>'9')
                    break;
                temp += (s2[j] - '0') * pow(10,k);
                k++;
            }
            if(temp == 0)
                temp = 1;
            if(j>=0 && s2[j]=='-')
            {
                a += temp;
            }
            else
            {
                a -= temp;
            }
            i = s2.find("x^2", i+1);
        }

        //查找x
        i = 0;
        i = s1.find("x", i);
        while(i != string::npos)
        {
            temp = 0;
            k = 0;
            flag = false;
            if(i+1 < len1 && s1[i+1] == '^')
            {
                i = s1.find("x", i+1);
                continue;
            }
            for(j=i-1; j>=0; j--)
            {
                if(s1[j]<'0' || s1[j]>'9')
                {
                    break;
                }
                temp += (s1[j] - '0') * pow(10,k);
                k++;
            }
            if(temp == 0)
                temp = 1;
            if(j>=0 && s1[j]=='-')
            {
                b -= temp;
            }
            else
            {
                b += temp;
            }
            i = s1.find("x", i+1);
        }
        i = 0;
        i = s2.find("x", i);
        while(i != string::npos)
        {
            temp = 0;
            k = 0;
            if(i+1 < len2 && s2[i+1] == '^')
            {
                i = s2.find("x", i+1);
                continue;
            }
            for(j=i-1; j>=0; j--)
            {
                if(s2[j]<'0' || s2[j]>'9')
                {
                    break;
                }
                temp += (s2[j] - '0') * pow(10,k);
                k++;
            }
            if(temp == 0)
                temp = 1;
            if(j>=0 && s2[j]=='-')
            {
                b += temp;
            }
            else
            {
                b -= temp;
            }
            i = s2.find("x", i+1);
        }

        //查找常数
        for(i=0; i<len1; ++i)
        {
            if(s1[i]<='9'&&s1[i]>='0')
            {
                if(i>0 && s1[i-1] == '^')
                    continue;
                if(i<len1-1 && s1[i+1] == 'x')
                    continue;
                temp = 0;
                j = i-1;
                while(i<len1)
                {
                    if(s1[i]>'9'||s1[i]<'0')
                        break;
                    temp = temp*10 + s1[i] - '0';
                    ++i;
                    if(i<len1-1 && s1[i+1] == 'x')
                    {
                        temp = 0;
                        break;
                    }
                }
                if(j>=0 && s1[j]=='-')
                {
                    c -= temp;
                }
                else
                {
                    c += temp;
                }
            }
        }
        for(i=0; i<len2; ++i)
        {
            if(s2[i]<='9'&&s2[i]>='0')
            {
                if(i>0 && s2[i-1] == '^')
                    continue;
                if(i<len2-1 && s2[i+1] == 'x')
                    continue;
                temp = 0;
                j=i-1;
                while(i<len2)
                {
                    if(s2[i]>'9'||s2[i]<'0')
                        break;
                    temp = temp*10 + s2[i] - '0';
                    ++i;
                    if(i<len2-1 && s2[i+1] == 'x')
                    {
                        temp = 0;
                        break;
                    }
                }
                if(j>=0 && s2[j]=='-')
                {
                    c += temp;
                }
                else
                {
                    c -= temp;
                }
            }
        }
        //cout<<s1<<endl<<s2<<endl;
        //cout<<a<<" "<<b<<" "<<c<<endl;
        if(b*b < 4*a*c || a==0)
            cout<<"No Solution"<<endl;
        else
        {
            double re1,re2,t;
            re1 = (0 - b - sqrt(b*b - 4*a*c))/(2*a);
            re2 = (0 - b + sqrt(b*b - 4*a*c))/(2*a);
            if(re1 > re2)
            {
                t = re1;
                re1 = re2;
                re2 = t;
            }
            cout<<setprecision(2)<<fixed<<re1<<" "<<re2<<endl;
        }
    }
    return 0;
}
