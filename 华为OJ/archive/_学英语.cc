#include <iostream>
#include <string>

using namespace std;

string s[]={"billion","million","thousand","hundred"};
string s1[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string s2[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string c=" ";

string parse3(int num)
{
    string result;
    int t;
    int flag=0;
    if(num>999)
    {
        t=num/1000;
        result+=(s1[t]+c+s[2]);
        flag=1;
        num%=1000;
    }
    if(num>99)
    {
        t=num/100;
        if(flag==1)
            result+=c;
        result+=(s1[t]+c+s[3]);
        flag=1;
        num%=100;
    }
    if(num>19)
    {
        t=num/10;
        if(flag==1)
            result+=" and ";
        result+=s2[t-2];
        t=num%10;
        if(t!=0)
            result+=c+s1[t];
    }
    else
    {
        if(flag==1&&num!=0)
            result+=" and ";
        if(num!=0)
            result+=s1[num];
    }
    return result;
}

string parse(long int num)
{
    string result;
    int t;
    int flag=0;
    if(num>=1000000000)
    {
        t=num/1000000000;
        result+=s1[t];
        result+=c+s[0];
        flag=1;
        num%=1000000000;
    }
    if(num>=1000000)
    {
        if(flag==1)
            result+=" and ";
        t=num/1000000;
        result+=parse3(t);
        result+=c+s[1];
        flag=1;
        num%=1000000;
    }
    if(num>=1000)
    {
        if(flag==1)
            result+=" and ";
        t=num/1000;
        result+=parse3(t);
        result+=c+s[2];
        flag=1;
        num%=1000;
    }
    if(num>0)
    {
        if(flag==1)
            result+=c;
        result+=parse3(num);
    }
    return result;
}

int main()
{
    long int num;
    while(cin>>num)
    {
        if(num>=10000000000||num<=0)
            cout<<"error"<<endl;
        else
            cout<<parse(num)<<endl;
    }
    return 0;
}





/*
#include <iostream>
#include <string>

using namespace std;

string s[]={"billion","million","thousand","hundred"};
string s1[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string s2[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string c=" ";

string parse3(int num)
{
    string result;
    int t;
    int flag=0;
    if(num>999)
    {
        t=num/1000;
        result+=(s1[t]+c+s[2]);
        flag=1;
        num%=1000;
    }
    if(num>99)
    {
        t=num/100;
        if(flag==1)
            result+=" and ";
        result+=(s1[t]+c+s[3]);
        flag=1;
        num%=100;
    }
    if(num>19)
    {
        t=num/10;
        if(flag==1)
            result+=" and ";
        result+=s2[t-2];
        t=num%10;
        if(t!=0)
            result+=c+s1[t];
    }
    else
    {
        if(flag==1&&num!=0)
            result+=" and ";
        if(num!=0)
            result+=s1[num];
    }
    return result;
}

string parse(long int num)
{
    string result;
    int t;
    int flag=0;
    if(num>=1000000000)
    {
        t=num/1000000000;
        result+=s1[t];
        result+=c+s[0];
        flag=1;
        num%=1000000000;
    }
    if(num>=1000000)
    {
        if(flag==1)
            result+=" and ";
        t=num/1000000;
        result+=parse3(t);
        result+=c+s[1];
        flag=1;
        num%=1000000;
    }
    if(num>=1000)
    {
        if(flag==1)
            result+=" and ";
        t=num/1000;
        result+=parse3(t);
        result+=c+s[2];
        flag=1;
        num%=1000;
    }
    if(num>0)
    {
        if(flag==1)
            result+=" and ";
        result+=parse3(num);
    }
    return result;
}

int main()
{
    long int num;
    while(cin>>num)
    {
        if(num>=10000000000||num<=0)
            cout<<"error"<<endl;
        else
            cout<<parse(num)<<endl;
    }
    return 0;
}
*/
