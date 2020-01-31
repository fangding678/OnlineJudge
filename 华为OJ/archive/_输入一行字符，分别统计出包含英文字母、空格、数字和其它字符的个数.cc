#include <iostream>
#include <string>

using namespace std;


class A
{
    public:
    string str;
    A() {}
    A(string s):str(s) {}
    int getEnglishCharCount(string s1);
    int getBlankCharCount(string s1);
    int getNumberCharCount(string s1);
    int getOtherCharCount(string s1);
};

int A::getEnglishCharCount(string s1)
{
    int num_a=0;
    for(string::iterator it=s1.begin();it!=s1.end();++it)
    {
        if(isalpha(*it))
            num_a++;
    }
    return num_a;
}
int A::getBlankCharCount(string s1)
{
    int num_b=0;
    for(string::iterator it=s1.begin();it!=s1.end();it++)
    {
        if(*it==' ')
            num_b++;
    }
    return num_b;
}
int A::getNumberCharCount(string s1)
{
    int num_n=0;
    for(string::iterator it=s1.begin();it!=s1.end();++it)
        if(isalnum(*it))
            num_n++;
    num_n-=A::getEnglishCharCount(s1);
    return num_n;
}
int A::getOtherCharCount(string s1)
{
    return s1.size()-A::getBlankCharCount(s1)-A::getEnglishCharCount(s1)-A::getNumberCharCount(s1);
}
int main()
{
    string s;
    while(getline(cin,s))
    {
        //  s=R"(1qazxsw23 edcvfr45tgbn hy67uj m,ki89ol.\\/;p0-=\\][)";
        //  s=R"+*(1qazxsw23 edcvfr45tgbn hy67uj m,ki89ol.\\/;p0-=\\][)+*";
        A a(s);
        cout<<a.getEnglishCharCount(a.str)<<endl<<a.getBlankCharCount(a.str)<<endl
        <<a.getNumberCharCount(a.str)<<endl<<a.getOtherCharCount(a.str)<<endl;
    }
    return 0;
}
